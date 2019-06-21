/* *************************************
 *  Weather Site JavaScript Functions
 ************************************* */
console.log("My javascript is being read.");

// Calculate the Windchill
function buildWC(speed, temp) {
    let feelTemp = document.getElementById("feelTemp");

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
    feelTemp.innerHTML = wc;
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
        newForcast.includes("blue skies")
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

function changeSummaryImage(condition) {
    // Get the container
    let curWeather = document.getElementById("curWeather");
    let sumImage = document.getElementById("sumImage");
    console.log(condition);
    switch (condition) {
        case "rain":
            console.log("rain");
            curWeather.setAttribute("class", "rain");
            sumImage.setAttribute("src", "../weather_images/rain_small.jpg");
            sumImage.setAttribute("alt", "Its a rainy day");
            break;
        case "clear":
            console.log("clear");
            curWeather.setAttribute("class", "clear");
            sumImage.setAttribute("src", "../weather_images/clear_small.jpg");
            sumImage.setAttribute("alt", "There are clear skies");
            break;
        case "cloud":
            console.log("cloud");
            curWeather.setAttribute("class", "cloud");
            sumImage.setAttribute("src", "../weather_images/clouds_small.jpg");
            sumImage.setAttribute("alt", "cloudy weather");
            break;
        case "fog":
            console.log("fog");
            curWeather.setAttribute("class", "fog");
            sumImage.setAttribute("src", "../weather_images/fog_small.jpg");
            sumImage.setAttribute("alt", "There is foggy weather");
            break;
        case "snow":
            console.log("snow");
            curWeather.setAttribute("class", "snow");
            sumImage.setAttribute("src", "../weather_images/snow_small.jpg");
            sumImage.setAttribute("alt", "Snow flurries in the forcast");
            break;
    }
}

function convertMeters(meters) {
    let feet = Math.floor(meters * 3.28084);
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
    /*if (i == 1) {
        hourlyListItems = '<li>' + " " + format_time(nextHour + i) + ': ' + hourlyTemps[i] + '&deg;F</li>';
    } else {
        hourlyListItems += '<li> | ' + format_time(nextHour + i) + ': ' + hourlyTemps[i] + '&deg;F</li>';
    }*/
    // The hourlyTemps variable holds an array of temperatures
    // Line 8 builds a list item showing the time for the next hour 
    // and then the first element (value in index 0) from the hourly temps array
    let hourlyListItems = '<li>' + format_time(nextHour) + ': ' + hourlyTemps[0] + '&deg;F </li>';
    // Build the remaining list items using a for loop
    for (let i = 1, x = hourlyTemps.length; i < x; i++) {
        hourlyListItems += '<li>' + format_time(nextHour + i) + ': ' + hourlyTemps[i] + '&deg;F </li>';
    }
    console.log('HourlyList is: ' + hourlyListItems);
    return hourlyListItems;
}

// Get the next hour based on the current time
let date = new Date();
let nextHour = date.getHours() + 1;