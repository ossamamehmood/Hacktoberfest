const num = Math.floor(Math.random() * 100) + 1;
let chances = 0;
let choice;
do {
  choice = prompt("Enter the your guess: ")
  if (choice > num) {
    console.log('Way too high!')
  } else if (choice < num) {
    console.log('Way too low!')
  } else {
    console.log(`You entered the correct number!! Your score is '${100 - chances}'`)
  }
  chances++
} while (choice != num)
