const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function generateRandomNumber(min, max) {
  return Math.floor(Math.random() * (max - min + 1) + min);
}

const minNumber = 1;
const maxNumber = 100;
const targetNumber = generateRandomNumber(minNumber, maxNumber);
let attempts = 0;

function guessNumber() {
  rl.question(`Guess a number between ${minNumber} and ${maxNumber}: `, (input) => {
    const guess = parseInt(input);

    if (isNaN(guess)) {
      console.log('Please enter a valid number.');
    } else {
      attempts++;

      if (guess === targetNumber) {
        console.log(`Congratulations! You guessed the number ${targetNumber} in ${attempts} attempts.`);
        rl.close();
      } else if (guess < targetNumber) {
        console.log('Try a higher number.');
        guessNumber();
      } else {
        console.log('Try a lower number.');
        guessNumber();
      }
    }
  });
}

console.log('Welcome to the Number Guessing Game!');
console.log(`I'm thinking of a number between ${minNumber} and ${maxNumber}.`);
guessNumber();
