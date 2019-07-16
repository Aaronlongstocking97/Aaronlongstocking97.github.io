/* *************************************
 *  Weather Site JavaScript Functions
 ************************************* */
console.log("My javascript is being read.");
"use strict";

let homeTitle = document.title;
let pages = document.getElementById('pages');
let acmeURL = "../js/acme.json";
let contentContainer = document.getElementById('main-content');
let contentContainers = document.getElementById('content');

NavBar(acmeURL);

function NavBar(acmeURL) {

    fetch(acmeURL)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR('Network response was not OK.');
        })
        .then(function (data) {
            console.log(data);
            const navLink = Object.keys(data);
            console.log(navLink);
            let navlist = buildNavBar(navLink);
            pages.innerHTML += navlist;
        })
}

function buildNavBar(navLink) {
    let link = '';
    navLink.forEach(element => {
        console.log("Navigation link created: " + element);
        link += '<li>' + element + '</li>';
    });
    return link;
}

function buildPage(acmeURL, navName) {
    fetch(acmeURL)
        .then(function (response) {
            if (response.ok) {
                return response.json();
            }
            throw new ERROR('Network response was not OK.');
        })
        .then(function (data) {
            // Check the data object that was retrieved
            console.log(data[navName]);

            let fullName = data[navName].name;
            document.title = fullName + ` | Acme, Inc.`;

            let title = data[navName].name;
            document.getElementById("title").innerHTML = title;
            console.log("Title name: " + title);

            let imgPath = data[navName].path;
            document.getElementById('imgPath').setAttribute("src", imgPath);
            console.log("Image path: " + imgPath);

            let info = data[navName].description;
            document.getElementById("info").innerHTML = info;
            console.log("Objects information: " + info);

            let manufacturer = data[navName].manufacturer;
            document.getElementById("manufacturer").innerHTML = manufacturer;
            console.log("Manufacturer name: " + manufacturer);

            let review = data[navName].reviews;
            document.getElementById("review").innerHTML = review;
            console.log("Objects review score: " + review);

            let price = data[navName].price;
            document.getElementById("price").innerHTML = price;
            console.log("Price of the Object $" + price);
        })
        .catch(function (error) {
            console.log('There was a fetch problem: ', error.message);
        })
}

pages.addEventListener("click", function (evt) {

    let navName = evt.target.innerHTML;
    // Only check for navigation names
    switch (navName) {
        case "Home":
            document.title = homeTitle;
            contentContainer.setAttribute('class', ''); // removes the hide class
            contentContainers.setAttribute('class', 'hide'); // removes the hide class
            break;
        case "Anvils":
        case "Explosives":
        case "Decoys":
        case "Traps":
            evt.preventDefault();
            contentContainer.setAttribute('class', 'hide'); // removes the hide class
            contentContainers.setAttribute('class', ''); // removes the hide class
            buildPage(acmeURL, navName);
            break;

        default:
            break;
    }
})