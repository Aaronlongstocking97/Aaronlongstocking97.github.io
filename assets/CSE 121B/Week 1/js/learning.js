console.log('Hello world');
var num = 10;
console.log('Num: ' + num);

function doesNothing(str) {
	if (!str) {
		console.log('Str does not exist');
	} else {
		console.log('Str exits: ' + str);
	}
}


doesNothing('100', 100);