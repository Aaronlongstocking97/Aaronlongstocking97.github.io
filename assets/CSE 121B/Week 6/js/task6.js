/* *************************************
 *  Final Project
 *  Week 6 - Random Quote Generator
 *  JavaScript Functions
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
      if (response.ok) {
        return response.json();
      }
      throw new ERROR("Response not OK.");
    })

    .then(function (data) {
      // Let's see what we got back
      console.log("Json object from Famous Quotes");
      console.log(data);

      let someAuthor = data[0].author;
      let someCategory = data[0].category;
      let someText = data[0].text;

      console.log("the author is: " + someAuthor);
      console.log("the category is: " + someCategory);
      console.log("the text is: " + someText);

      // Store data to localstorage
      storage.setItem("someAuthor", someAuthor);
      storage.setItem("someCategory", someCategory);
      storage.setItem("someText", someText);
    })
    .catch((error) => console.log("There was a build error: ", error))
    .then(function () {
      // Build the page for viewing
      buildPage();
      console.log("buildPage was successful");
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

getQuote();
