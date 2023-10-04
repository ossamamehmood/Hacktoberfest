// Array of jokes
const jokes = [
  "Why don't scientists trust atoms? Because they make up everything!",
  "Parallel lines have so much in common. It's a shame they'll never meet.",
  "I told my wife she was drawing her eyebrows too high. She looked surprised.",
  "Why don't skeletons fight each other? They don't have the guts.",
  "I used to play piano by ear, but now I use my hands.",
  "What did one wall say to the other wall? 'I'll meet you at the corner!'",
];

// Function to select a random joke from the array
function getRandomJoke() {
  const randomIndex = Math.floor(Math.random() * jokes.length);
  return jokes[randomIndex];
}

// Logging a random joke to the console
console.log(getRandomJoke());
