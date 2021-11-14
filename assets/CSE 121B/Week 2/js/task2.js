/* Lesson 2 */

/* VARIABLES */

// Step 1: declare and instantiate a variable to hold your name
const NAME = 'Aaron Jones';

// Step 2: place the value of the name variable into the HTML file (hint: document.querySelector())
document.querySelector('#name').innerHTML = NAME;

// Step 3: declare and instantiate a variable to hold the current year
const YEAR = 2021;

// Step 4: place the value of the current year variable into the HTML file
document.querySelector('#year').innerHTML = YEAR;

// Step 5: declare and instantiate a variable to hold the name of your picture
const PICTURE = '/Week 2/images/IMG_3803.JPG';
// Step 6: copy your image into the "images" folder

// Step 7: place the value of the picture variable into the HTML file (hint: document.querySelector().setAttribute())
document.querySelector('img').setAttribute('src', PICTURE);



/* ARRAYS */

// Step 1: declare and instantiate an array variable to hold your favorite foods
const FAVFOODS = ['Pork', ' Sushi', ' Ribs', ' Bacon'];

// Step 2: place the values of the favorite foods variable into the HTML file
document.querySelector('#food').innerHTML = FAVFOODS;

// Step 3: declare and instantiate a variable to hold another favorite food
const ADDITIONALFAVFOOD = ' Sausage';

// Step 4: add the variable holding another favorite food to the favorite food array
FAVFOODS.push(ADDITIONALFAVFOOD);

// Step 5: repeat Step 2
document.querySelector('#food').innerHTML = FAVFOODS;

// Step 6: remove the first element in the favorite foods array
FAVFOODS.shift();

// Step 7: repeat Step 2
document.querySelector('#food').innerHTML = FAVFOODS;

// Step 8: remove the last element in the favorite foods array
favoriteFoods.pop();

// Step 7: repeat Step 2
document.querySelector('#food').textContent = favoriteFoods;


