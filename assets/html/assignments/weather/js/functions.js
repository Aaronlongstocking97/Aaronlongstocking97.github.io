/* *************************************
 *  Weather Site JavaScript Functions
 ************************************* */
console.log("My javascript is being read.");

var idHeader = {
    headers: {
        "User-Agent": "Student Learning Project - jon17049@byui.edu"
    }
};


// Calculate the Windchill
function buildWC(speed, temp) {
    //let feelTemp = document.getElementById.innerHTML("feelTemp");

    console.log(temp);
    console.log(speed);

    // Compute the windchill
    let wc =
        35.74 +
        0.6215 * temp -
        35.75 * Math.pow(speed, 0.16) +
        0.4275 * temp * Math.pow(speed, 0.16);
    console.log(wc);

    // Round the answer down to integer
    wc = Math.floor(wc);

    // If chill is greater than temp, return the temp 
    wc = wc > temp ? temp : wc;

    // Display the windchill
    console.log(wc);
    // wc = 'Feels like '+wc+'°F';
    storage.setItem('feelTemp', wc);
    let feelTemp = storage.getItem('feelTemp');
    document.getElementById('feelTemp').innerHTML = Number(feelTemp).toFixed();
}

// Wind Dial Function
function windDial(direction) {
    // Get the container
    let dial = document.getElementById("dial");
    console.log(direction);
    // Determine the dial class
    switch (direction.toUpperCase()) {
        case "North":
        case "N":
            dial.setAttribute("class", "n"); //"n" is the CSS rule selector
            break;
        case "NE":
        case "NNE":
        case "ENE":
            dial.setAttribute("class", "ne");
            break;
        case "NW":
        case "NNW":
        case "WNW":
            dial.setAttribute("class", "nw");
            break;
        case "South":
        case "S":
            dial.setAttribute("class", "s");
            break;
        case "SE":
        case "SSE":
        case "ESE":
            dial.setAttribute("class", "se");
            break;
        case "SW":
        case "SSW":
        case "WSW":
            dial.setAttribute("class", "sw");
            break;
        case "East":
        case "E":
            dial.setAttribute("class", "e");
            break;
        case "West":
        case "W":
            dial.setAttribute("class", "w");
            break;
    }
}

function getCondition(forcast) {
    console.log(forcast);

    let newForcast = forcast.toLowerCase();
    // Determine the forcast
    if (
        newForcast.includes("rain") ||
        newForcast.includes("shower") ||
        newForcast.includes("wet") ||
        newForcast.includes("thunderstorms")
    ) {
        console.log("rain");
        return "rain";
    } else if (
        newForcast.includes("clear") ||
        newForcast.includes("blue skies") ||
        newForcast.includes("sunny")
    ) {
        console.log("clear");
        return "clear";
    } else if (
        newForcast.includes("cloud") ||
        newForcast.includes("overcast") ||
        newForcast.includes("gray")
    ) {
        console.log("cloud");
        return "cloud";
    } else if (
        newForcast.includes("fog") ||
        newForcast.includes("mist") ||
        newForcast.includes("haze") ||
        newForcast.includes("smog")
    ) {
        console.log("fog");
        return "fog";
    } else if (
        newForcast.includes("snow") ||
        newForcast.includes("blizzard") ||
        newForcast.includes("sleet") ||
        newForcast.includes("hail") ||
        newForcast.includes("flakes") ||
        newForcast.includes("flurries")
    ) {
        console.log("snow");
        return "snow";
    }
}

// let condition = getCondition(forcast);

function changeSummaryImage(condition) {
    // Get the container
    let curWeather = document.getElementById("curWeather");
    //let sumImage = document.getElementById("sumImage");
    console.log(condition);
    switch (condition) {
        case "rain":
            console.log("rain");
            curWeather.setAttribute("class", "rain");
            //sumImage.setAttribute("src", "../weather_images/rain_small.jpg");
            //sumImage.setAttribute("alt", "Its a rainy day");
            break;
        case "clear":
            console.log("clear");
            curWeather.setAttribute("class", "clear");
            //sumImage.setAttribute("src", "../weather_images/clear_small.jpg");
            //sumImage.setAttribute("alt", "There are clear skies");
            break;
        case "cloud":
            console.log("cloud");
            curWeather.setAttribute("class", "cloud");
            //sumImage.setAttribute("src", "../weather_images/clouds_small.jpg");
            //sumImage.setAttribute("alt", "cloudy weather");
            break;
        case "fog":
            console.log("fog");
            curWeather.setAttribute("class", "fog");
            //sumImage.setAttribute("src", "../weather_images/fog_small.jpg");
            //sumImage.setAttribute("alt", "There is foggy weather");
            break;
        case "snow":
            console.log("snow");
            curWeather.setAttribute("class", "snow");
            //sumImage.setAttribute("src", "../weather_images/snow_small.jpg");
            //sumImage.setAttribute("alt", "Snow flurries in the forcast");
            break;
    }
}

function convertMeters(stationElevation) {
    let feet = Math.floor(stationElevation * 3.28084);
    return feet;
}

// Convert, Format time to 12 hour format
function format_time(hour) {
    if (hour > 23) {
        hour -= 24;
    }
    let amPM = (hour > 11) ? "pm" : "am";
    if (hour > 12) {
        hour -= 12;
    }
    if (hour == 0) {
        hour = "12";
    }
    return hour + amPM;
}

// Build the hourly temperature list
function buildHourlyData(nextHour, hourlyTemps) {
    // Data comes from a JavaScript object of hourly temp name - value pairs
    // Next hour should have a value between 0-23
    // The hourlyTemps variable holds an array of temperatures
    // Line 8 builds a list item showing the time for the next hour 
    // and then the first element (value in index 0) from the hourly temps array
    console.log(hourlyTemps);
    let hourlyListItems = '<li>' + format_time(nextHour) + ': ' + hourlyTemps[0] + '&deg;F </li>';
    console.log(hourlyListItems);
    // Build the remaining list items using a for loop
    for (let i = 1, x = hourlyTemps.length; i < x; i++) {
        hourlyListItems += '<li>' + format_time(nextHour + i) + ': ' + hourlyTemps[i] + '&deg;F </li>';
    }
    console.log('HourlyList is: ' + hourlyListItems);
    return hourlyListItems;
}

// Gets location information from the NWS API
function getLocation(locale) {
    const URL = "https://api.weather.gov/points/" + locale;
    // NWS User-Agent header (built above) will be the second parameter 
    fetch(URL, idHeader)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR('Response not OK.');
        })
        .then(function (data) {
            // Let's see what we got back
            console.log('Json object from getLocation function:');
            console.log(data);
            // Store data to localstorage 
            storage.setItem("locName", data.properties.relativeLocation.properties.city);
            storage.setItem("locState", data.properties.relativeLocation.properties.state);


            getHourly(data.properties.forecastHourly);

            // Next, get the weather station ID before requesting current conditions 
            // URL for station list is in the data object
            let forecastURL = data.properties.forecast;
            console.log(forecastURL);
            let stationsURL = data.properties.observationStations;
            // Call the function to get the list of weather stations
            getForcast(forecastURL);
            getStationId(stationsURL);
        })
        .catch(error => console.log('There was a getLocation error: ', error))
} // end getLocation function

// Gets weather station list and the nearest weather station ID from the NWS API
function getForcast(local) {
    const URL = local;
    // NWS User-Agent header (built above) will be the second parameter
    fetch(URL, idHeader)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR("Response not OK.");
        })
        .then(function (data) {
            // Let's see what we got back
            console.log("From getForcast function:");
            console.log(data);

            // Store station ID and elevation (in meters - will need to be converted to feet)
            let high = data.properties.periods[0].temperature;
            let low = data.properties.periods[1].temperature;
            let sumData = data.properties.periods[0].icon;;
            let iconForecast = data.properties.periods[0].detailedForecast;
            let gustData = data.properties.periods[0].windSpeed;

            console.log(sumData);
            console.log("high temp and low temp are: " + high + ", " + low);

            // Store data to localstorage
            storage.setItem('gustData', gustData);
            storage.setItem('iconForecast', iconForecast);
            storage.setItem('sumImage', sumData);
            storage.setItem('highTemp', high);
            storage.setItem('lowTemp', low);
            // Request the Current Weather for this station
        })
        .catch(error => console.log("There was a getForecast error: ", error));
} // end getStationId function

// Gets weather station list and the nearest weather station ID from the NWS API
function getStationId(stationsURL) {
    // NWS User-Agent header (built above) will be the second parameter 
    fetch(stationsURL, idHeader)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR('Response not OK.');
        })
        .then(function (data) {
            // Let's see what we got back
            console.log('From getStationId function:');
            console.log(data);

            // Store station ID and elevation (in meters - will need to be converted to feet) 
            let stationId = data.features[0].properties.stationIdentifier;
            let stationElevation = data.features[0].properties.elevation.value;
            console.log('Station and Elevation are: ' + stationId, stationElevation);
            let Elevationft = convertMeters(stationElevation);

            // Store data to localstorage 
            storage.setItem("stationId", stationId);
            storage.setItem("stationElevation", Elevationft);

            // Request the Current Weather for this station 
            getWeather(stationId);
        })
        .catch(error => console.log('There was a getStationId error: ', error))
} // end getStationId function

// Gets current weather information for a specific weather station from the NWS API
function getWeather(stationId) {
    // This is the URL for current observation data 
    const URL = 'https://api.weather.gov/stations/' + stationId + '/observations/latest';
    // NWS User-Agent header (built above) will be the second parameter 
    fetch(URL, idHeader)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR('Response not OK.');
        })
        .then(function (data) {
            // Let's see what we got back
            console.log('From getWeather function:');
            console.log(data);


            let temperature = data.properties.temperature.value;
            let temperatureF = convertToFahrenheit(temperature);
            let direct = data.properties.windDirection.value;
            console.log(direct);
            let wDirection = convertWindDirection(direct);
            console.log(wDirection);

            // Store weather information to localStorage 
            storage.setItem('temp', temperatureF);
            storage.setItem('precip', data.properties.precipitationLastHour.value);
            storage.setItem('wind', data.properties.windSpeed.value);
            storage.setItem('direction', wDirection);
            //storage.setItem('gusts', data.properties.windGust.value);
            storage.setItem('summary', data.properties.textDescription);

            console.log(storage.getItem("wind"))
        })
        .catch(error => console.log('There was a getWeather error: ', error))
        .then(function () {
            // Build the page for viewing 
            buildPage();
        })
} // end getWeather function

function getHourly(hourlyURL) {
    // NWS User-Agent header (built above) will be the second parameter 
    fetch(hourlyURL, idHeader)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR('Response not OK.');
        })
        .then(function (data) {
            // Let's see what we got back
            console.log('From getHourly function:');
            console.log(data);
            // Store weather information to localStorage 
            let hourlyTemps = [];

            for (let i = 0; i < 13; i++) {
                hourlyTemps[i] = data.properties.periods[i].temperature;
            }
            console.log(hourlyTemps);
            let hours = buildHourlyData(nextHour, hourlyTemps);
            storage.setItem('hourTemps', hours);

        })
        .catch(error => console.log('There was a getHourly error: ', error))
} // end getHourly function

// Populate the current location weather page
function buildPage() {

    // Let's see what we got back
    console.log('From buildPage function:');
    // Task 1 - Feed data to WC, Dial, Image, Meters to feet and hourly temps functions
    // Get weather information from localStorage
    let image = storage.getItem("sumImage");
    let speed = storage.getItem('wind');
    let temp = storage.getItem('temp');
    let highTemp = storage.getItem('highTemp');
    let lowTemp = storage.getItem('lowTemp');
    let direction = storage.getItem('direction');
    let gusts = storage.getItem('gustData');
    let forcast = storage.getItem('summary');
    let iconSum = storage.getItem('iconForecast');
    let meters = storage.getItem("stationElevation");
    console.log(meters);
    let tempHours = storage.getItem('hourTemps');
    let city = storage.getItem('locName');
    let state = storage.getItem('locState');
    let latitude = storage.getItem('lat');
    let longitude = storage.getItem('long');

    console.log(storage.getItem('wind'));

    // Task 2 - Populate location information
    // Task 3 - Populate weather information
    document.getElementById('wspeed').innerHTML = speed;
    document.getElementById('currTemp').innerHTML = Number(temp).toFixed();
    document.getElementById('high').innerHTML = highTemp;
    document.getElementById('low').innerHTML = lowTemp;
    document.getElementById('wDirect').innerHTML = direction.toUpperCase();
    document.getElementById('wRange').innerHTML = gusts;
    document.getElementById('weatherCon').innerHTML = forcast;
    document.getElementById('icon').innerHTML = "<img src='" + image + "'/>";
    document.getElementById('iconSum').innerHTML = iconSum;
    document.getElementById('elevation').innerHTML = Number(meters).toFixed();
    document.getElementById('hourlyTemps').innerHTML = tempHours;
    document.getElementById('locName').innerHTML = city + ', ' + state;
    document.getElementById('locLat').innerHTML = Number(latitude).toFixed(2);
    document.getElementById('locLong').innerHTML = Number(longitude).toFixed(2);


    console.log(meters);



    // Task 4 - Hide status and show main
    let statusContainer = document.getElementById('status');
    let contentContainer = document.getElementById('main-content');

    contentContainer.setAttribute('class', ''); // removes the hide class
    statusContainer.setAttribute('class', 'hide'); // hides the status container
    buildWC(speed, temp);
    windDial(direction);
    let condition = getCondition(forcast);
    changeSummaryImage(condition);

    convertToFahrenheit(temp, tempHours);


} // end buildPage function

function convertToFahrenheit(temperature) {
    let fTemp = ((temperature * (9 / 5)) + 32);
    return fTemp;
}

function convertWindDirection(direction) {
    console.log(direction);
    if (direction >= 350 || direction <= 10) {
        direction = 'n';
    } else if (direction > 10 && direction <= 80) {
        direction = 'ne';
    } else if (direction > 80 && direction <= 100) {
        direction = 'e';
    } else if (direction > 100 && direction <= 170) {
        direction = 'se';
    } else if (direction > 170 && direction <= 190) {
        direction = 's';
    } else if (direction > 190 && direction <= 260) {
        direction = 'sw';
    } else if (direction > 260 && direction <= 280) {
        direction = 'w';
    } else if (direction > 280 && direction <= 350) {
        direction = 'nw';
    }

    return direction;

}

// Setup localStorage
var storage = window.localStorage;

// Get the next hour based on the current time
let date = new Date();
let nextHour = date.getHours() + 1;