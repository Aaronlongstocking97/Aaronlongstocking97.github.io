/* Project Week 6 */
/* Random Quote Generator */
/* VARIABLES */

/*** 
// Step 1: declare and instantiate a variable to hold your name
const NAME = "Aaron Jones";

// Step 2: place the value of the name variable into the HTML file (hint: document.querySelector())
document.querySelector("#name").innerHTML = NAME;

// Step 3: declare and instantiate a variable to hold the current year
const YEAR = 2021;

// Step 4: place the value of the current year variable into the HTML file
document.querySelector("#year").innerHTML = YEAR;

// Step 5: declare and instantiate a variable to hold the name of your picture
const PICTURE = "/assets/CSE 121B/Week 2/images/IMG_3803.JPG";
// Step 6: copy your image into the "images" folder

// Step 7: place the value of the picture variable into the HTML file (hint: document.querySelector().setAttribute())
document.querySelector("img").setAttribute("src", PICTURE);

 ARRAYS 

// Step 1: declare and instantiate an array variable to hold your favorite foods
const FAVFOODS = ["Pork", " Sushi", " Ribs", " Bacon"];

// Step 2: place the values of the favorite foods variable into the HTML file
document.querySelector("#food").innerHTML = FAVFOODS;

// Step 3: declare and instantiate a variable to hold another favorite food
const ADDITIONALFAVFOOD = " Sausage";

// Step 4: add the variable holding another favorite food to the favorite food array
FAVFOODS.push(ADDITIONALFAVFOOD);

// Step 5: repeat Step 2
document.querySelector("#food").innerHTML = FAVFOODS;

// Step 6: remove the first element in the favorite foods array
FAVFOODS.shift();

// Step 7: repeat Step 2
document.querySelector("#food").innerHTML = FAVFOODS;

// Step 8: remove the last element in the favorite foods array
favoriteFoods.pop();

// Step 7: repeat Step 2
document.querySelector("#food").innerHTML = FAVFOODS;
***/

/* *************************************
 *  Weather Site JavaScript Functions
 ************************************* */
console.log("My javascript is being read.");

function getQuote() {
  const URL =
    "https://famous-quotes4.p.rapidapi.com/random?category=all&count=2";
  fetch(URL, {
    method: "GET",
    headers: {
      "x-rapidapi-host": "famous-quotes4.p.rapidapi.com",
      "x-rapidapi-key": "22c3f5e831msh69107dfc8e3999dp1d8b43jsn2f0512073699",
    },
  })
    .then(function (response) {
      console.log(response);
      if (response.ok) {
        return response.json();
      }
      throw new ERROR("Response not OK.");
    })
    .catch((error) => console.log("There was a build error: ", error))
    .then(function () {
      // Build the page for viewing
      buildPage();
      console.log("buildPage");
    });
}

function buildPage() {
  let author = storage.getItem("someAuthor");
  let category = storage.getItem("someCategory");
  let text = storage.getItem("someText");

  document.getElementById("author").innerHTML = author;
  document.getElementById("category").innerHTML = category;
  document.getElementById("text").innerHTML = text;
} // end buildPage function

// Setup localStorage
var storage = window.localStorage;

/***
const url = "https://pokeapi.co/api/v2/pokemon/ditto";
const results = fetch(url);
console.log(results);

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
            let wDirection = convertWindDirection(direct);
            console.log("This is the wind direction angle: " + wDirection);

            // Store weather information to localStorage 
            storage.setItem('temp', temperatureF);
            storage.setItem('wind', data.properties.windSpeed.value);
            storage.setItem('direction', wDirection);
            storage.setItem('summary', data.properties.textDescription);

        })
        .catch(error => console.log('There was a getWeather error: ', error))
        .then(function () {
            // Build the page for viewing 
            buildPage();
        })
} // end getWeather function
***/
