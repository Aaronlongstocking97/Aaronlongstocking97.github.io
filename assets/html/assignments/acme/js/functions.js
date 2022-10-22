/* *************************************
 *  Weather Site JavaScript Functions
 ************************************* */
console.log("My javascript is being read.");
("use strict");

// Variables created to hold data or assign data to elements
let homeTitle = document.title;
let pages = document.getElementById("pages");
let acmeURL = "../js/acme.json";
let contentContainer = document.getElementById("main-content");
let contentContainers = document.getElementById("content");

// Function call to build the navigation bar
NavBar(acmeURL);

function NavBar(acmeURL) {
    fetch(acmeURL)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR("Network response was not OK.");
        })
        .then(function (data) {
            console.log(data);
            const navLink = Object.keys(data);
            console.log(navLink);
            let navlist = buildNavBar(navLink);
            pages.innerHTML += navlist;
        });
} // end NavBar function

function buildNavBar(navLink) {
    // navLink is passed in to create each individual element.
    // navLInk is also tied to the data the is passed in from the Json file
    // and tied to the variable acmeURL.
    let link = "";
    navLink.forEach(element => {
        console.log("Navigation link created: " + element);
        link += "<li>" + element + "</li>";
    });
    return link;
} // end buildNavBar function and return a variable 'Link'

function buildPage(acmeURL, navName) {
    fetch(acmeURL)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR("Network response was not OK.");
        })
        .then(function (data) {
            // Check the data object that was retrieved
            console.log(data[navName]);

            // Set title element for the tab window
            let fullName = data[navName].name;
            document.title = fullName + ` | Acme, Inc.`;

            // Set title element for the page
            let title = data[navName].name;
            document.getElementById("title").innerHTML = title;
            console.log("Title name: " + title);

            // Set content image
            let imgPath = data[navName].path;
            document.getElementById("imgPath").setAttribute("src", imgPath);
            console.log("Image path: " + imgPath);

            // Set content description
            let info = data[navName].description;
            document.getElementById("info").innerHTML = info;
            console.log("Objects information: " + info);

            // Set manufacturer information
            let manufacturer = data[navName].manufacturer;
            document.getElementById("manufacturer").innerHTML = manufacturer;
            console.log("Manufacturer name: " + manufacturer);

            // Set review data
            let review = data[navName].reviews;
            document.getElementById("review").innerHTML = review;
            console.log("Objects review score: " + review);

            // Set price of object listed
            let price = data[navName].price;
            document.getElementById("price").innerHTML = price;
            console.log("Price of the Object $" + price);
        })
        .catch(function (error) {
            console.log("There was a fetch problem: ", error.message);
        });
} // end buildPage function

pages.addEventListener("click", function (evt) {
    let navName = evt.target.innerHTML;
    // Only check for navigation names
    switch (navName) {
        case "Home":
            document.title = homeTitle;
            // Change the status of the containers
            contentContainer.setAttribute("class", ""); // removes the hide class
            contentContainers.setAttribute("class", "hide"); // removes the hide class
            break;
        case "Anvils":
        case "Explosives":
        case "Decoys":
        case "Traps":
            evt.preventDefault();
            // Change the status of the containers
            contentContainer.setAttribute("class", "hide"); // removes the hide class
            contentContainers.setAttribute("class", ""); // removes the hide class
            // Build the page for viewing 
            buildPage(acmeURL, navName);
            break;

        default:
            break;
    }
}); // end the event listener