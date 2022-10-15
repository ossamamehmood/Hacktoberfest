let randomNumber = Math.floor(Math.random() * 10) + 1;
let num1 = randomNumber;
let num2 = randomNumber;
let newCard = randomNumber;
let sum = num1 + num2;
let message = " ";
let j = 0;
let l = 0;
let numberOfWins = 0;
//let newCards = " ";
let cardArray = [num1, num2];

//elemnets getters
let cardsBox = document.getElementById("cards");
let sumBox = document.getElementById("sum");
let textArea = document.getElementById("textarea");
let btnStart = document.querySelector(".btn-start");
let btnReset = document.querySelector(".btn-reset");
let btnNew = document.querySelector(".btn-new");
btnStart.addEventListener("click", startGame);
btnNew.addEventListener("click", drawCard);
btnReset.addEventListener("click", reset);

function renderGame() {
  j++;
  let cards = " ";
  for (let i = 0; i < cardArray.length; i++) {
    cards += cardArray[i] + " ";
  }
  cardsBox.textContent = "Cards: " + cards;

  sumBox.textContent = "Sum:" + " " + sum;

  if (sum <= 20) {
    message = "Do you want to draw a new card? ";
  } else if (sum === 21) {
    message = "You have blackjack!";
    numberOfWins++;
  } else {
    message = "You're out of the game ...Loser!";
  }

  textArea.textContent = message;
}

function drawCard() {
  if (j < 1 || sum >= 21) {
    return;
  }
  sum += newCard;
  cardArray.push(newCard);
  renderGame();
}

function startGame() {
  renderGame();
}

function reset() {
  l++;
  cardsBox.textContent = "Cards: ";
  (sumBox.textContent = "Sum: "), (cards = "");
  sum = num1 + num2;
  textArea.textContent = "Want to play a game ?";
  cardArray = [num1, num2];
  sum = num1 + num2;
  newCard = Math.floor(Math.random() * (11 - 2 + 1)) + 2;
  num1 = Math.floor(Math.random() * (10 - 2 + 1)) + 1;
  num2 = Math.floor(Math.random() * (9 - 2 + 1));
  newCard = Math.floor(Math.random() * (11 - 2 + 1)) + 2;
  sum = num1 + num2;
  message = " ";
  j = 0;
  cardArray = [num1, num2];
  winOrLose();
}

function winOrLose() {
  let response = " ";
  if (l === 5) {
    if (numberOfWins < 1) {
      response = "No BlackJack....you were born a loser!<br>0/5";
    } else if (numberOfWins < 2) {
      response = "Atleast you got 1 right...Nope<br>youre still a loser<br>1/5";
    } else if (numberOfWins < 3) {
      response = "just 2...not a loser but far from a winner!<br>2/5";
    } else if (numberOfWins < 4) {
      response = "okay okay ....did good<br>3/5";
    } else if (numberOfWins < 5) {
      response =
        "NICE!<br>you did really good and you almost got perfect record<br>4/5";
    } else {
      response = "CONGRATULATIONS!YOU GOT A PERFECT SCORE<br> 5/5";
    }
    textArea.textContent = " ";
    textArea.innerHTML = response;
  }
}
