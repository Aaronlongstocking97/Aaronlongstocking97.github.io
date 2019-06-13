/* *************************************
 *  Weather Site JavaScript Functions
 ************************************* */
console.log('My javascript is being read.');

// Variables for Function Use
const temp = 40;
const speed = 5;
const direction = "NW"; //Set your own value
let forcast = "snow";
let condition = getCondition(forcast);
let elevation = document.getElementById("elevation");
let meters = elevation.innerHTML;

// Calculate the Windchill
function buildWC(speed, temp) {
    const feelTemp = document.getElementById('feelTemp');

    // Compute the windchill
    let wc = 35.74 + 0.6215 * temp - 35.75 * Math.pow(speed, 0.16) + 0.4275 * temp * Math.pow(speed, 0.16);
    console.log(wc);

    // Round the answer down to integer
    wc = Math.floor(wc);

    // If chill is greater than temp, return the temp
    wc = (wc > temp) ? temp : wc;

    // Display the windchill
    console.log(wc);
    // wc = 'Feels like '+wc+'°F';
    feelTemp.innerHTML = wc;
}

// Wind Dial Function
function windDial(direction) {
    // Get the container
    const dial = document.getElementById("dial");
    console.log(direction);
    // Determine the dial class
    switch (direction) {
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
    // Get the container
    // const condition = document.getElementById("condition");
    console.log(forcast);
    // Determine the forcast 
    switch (forcast.toLowerCase()) {
        case "rain":
            console.log("rain");
            return "rain"; //"rain" is the CSS rule selector
        case "clear":
            console.log("clear");
            return "clear";
        case "cloud":
            console.log("cloud");
            return "cloud";
        case "fog":
            console.log("fog");
            return "fog";
        case "snow":
            console.log("snow");
            return "snow";
    }
}

// console.log(`Testing the condition ${condition}`);

function changeSummaryImage(condition) {
    // Get the container
    const curWeather = document.getElementById("curWeather");
    const sumImage = document.getElementById("sumImage");
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

// console.log(`Original meters: ${elevation.innerHTML}`);

function convertMeters(meters) {
    let feet = Math.floor(meters * 3.28084)
    return feet;
}

buildWC(speed, temp);
windDial(direction);
changeSummaryImage(condition);
elevation.innerHTML = convertMeters(meters);
// console.log(`new feet: ${elevation.innerHTML}`);