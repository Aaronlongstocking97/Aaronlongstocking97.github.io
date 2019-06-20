/* *************************************
 *  Weather Site JavaScript Functions
 ************************************* */
"use strict";
console.log("My javascript is being read.");

let pageNav = document.getElementById('page-nav');
let statusContainer = document.getElementById('status');
let contentContainer = document.getElementById('main-content');

let weatherURL = "js/weather.json";

function fetchData(weatherURL) {
    let cityName = 'Greenville'; // The data we want from the weather.json file
    fetch(weatherURL)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR('Network response was not OK.');
        })
        .then(function (data) {
            // Check the data object that was retrieved
            console.log(data);
            // data is the full JavaScript object, but we only want the greenville part
            // shorten the variable and focus only on the data we want to reduce typing
            let g = data[cityName];

            // ************ Get the content ******************************

            // Get the location data
            let locName = g.City;
            let locState = g.State;
            let locLong = g.Longitude;
            let locLat = g.Latitude;
            let locElev = g.Elevation;
            let locZip = g.Zip;
            // Put them together
            let fullName = locName + ', ' + locState;
            let locDescript = 'Zip: ' + locZip + ' | Elavation: ' + locElev + 'ft. | Location: ' + locLat + '° N, ' + locLong + '° W';
            // See if it worked
            console.log('fullName is: ' + fullName);
            console.log(locDescript);

            // Get the temperature data
            let tempH = g.High;
            let tempL = g.Low;
            let temp = g.Temp;
            // Put them together
            let currtemp = temp + '°F';
            let currLHtemp = tempH + '°F ' + tempL + '°F';
            // See if it worked
            console.log('The current temp is: ' + currtemp);
            console.log('The current high and low is: ' + currLHtemp);

            // Get the wind data 
            let currWind = g.Wind;
            let currDirect = g.Direction;
            let windRange = g.Gusts;
            // Put them together
            let windDescript = 'Wind: ' + currWind + ' mph';
            let windDirect = 'Direction: ' + currDirect;
            let windgusts = 'Gusts: ' + windRange + ' mph';
            // See if it worked
            console.log(windDescript);
            console.log(windDirect);
            console.log(windgusts);

            // Get the current conditions
            let currSum = g.Summary;
            let currPrecip = g.Precip;
            // Put them together
            let weatherSum = 'Weather Summary: ' + currSum;
            let precipitation = 'Current Precipitation: ' + currPrecip + ' in';
            // See if it worked
            console.log(weatherSum);
            console.log(precipitation);

            // Get the hourly data 
            let hourlyTemps = g.Hourly;
            // Put them together
            let weatherHours = 'Hourly Temperatures: ' + hourlyTemps;
            // See if it worked
            console.log(weatherHours);


            // ************ Display the content ******************************
            // Set the title with the location name at the first
            // Gets the title element so it can be worked with
            let pageTitle = document.getElementById('page-title');
            // Create a text node containing the full name 
            let fullNameNode = document.createTextNode(fullName);
            // inserts the fullName value before any other content that might exist
            pageTitle.insertBefore(fullNameNode, pageTitle.childNodes[0]);
            // When this is done the title should look something like this:
            // Greenville, SC | The Weather Site

            // Set the Location information
            // Get the h1 to display the city location
            let contentHeading = document.getElementById('locName');
            console.log(contentHeading);
            contentHeading.innerHTML = fullName;
            // The h1 in main h1 should now say "Greenville, SC"


            // Set the temperature information
            // Zip Information
            let tempLoc = document.getElementById('zip1');
            console.log(tempLoc);
            tempLoc.innerHTML = locZip;

            // Elevation Information
            let tempElev = document.getElementById('elevation');
            console.log(tempElev);
            tempElev.innerHTML = convertMeters(locElev);;

            // Latitude Information
            let tempLat = document.getElementById('locLat');
            console.log(tempLat);
            tempLat.innerHTML = locLat;

            // Longitude Information
            let tempLong = document.getElementById('locLong');
            console.log(tempLong);
            tempLong.innerHTML = locLong;

            // Set the wind information
            // Current Wind Speed
            let liveWind = document.getElementById('wspeed');
            console.log(liveWind);
            liveWind.innerHTML = currWind;

            // Current Wind Direction
            let liveDirect = document.getElementById('wDirect');
            console.log(liveDirect);
            liveDirect.innerHTML = currDirect;

            // Current Wind Ranges
            let gustRange = document.getElementById('wRange');
            console.log(gustRange);
            gustRange.innerHTML = windRange;

            // Set the current conditions information
            let currCon = document.getElementById('weatherCon');
            console.log(currCon);
            currCon.innerHTML = currSum;

            // Set Temperature Conditions
            // Current Temperature
            let localTemp = document.getElementById("currTemp");
            console.log(localTemp);
            localTemp.innerHTML = temp;

            // Daily High Temperature
            let localH = document.getElementById("high");
            console.log(localH);
            localH.innerHTML = tempH;

            // Daily Low Temperature 
            let localL = document.getElementById("low");
            console.log(localL);
            localL.innerHTML = tempL;

            // Set the hourly temperature information
            let tempHours = document.getElementById("hourlyTemps");
            console.log(tempHours);
            tempHours.innerHTML = buildHourlyData(nextHour, hourlyTemps);


            // Change the status of the containers
            contentContainer.setAttribute('class', ''); // removes the hide class
            statusContainer.setAttribute('class', 'hide'); // hides the status container
        })
        .catch(function (error) {
            console.log('There was a fetch problem: ', error.message);
            statusContainer.innerHTML = 'Sorry, the data could not be processed.';
        })
}

buildWC(speed, temp);
windDial(direction);
changeSummaryImage(condition);
elevation.innerHTML = convertMeters(meters);
fetchData(weatherURL);