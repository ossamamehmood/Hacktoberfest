#!/bin/bash

# This script allows two players to play a game of Rock, Paper, Scissors.
# Player 1 will be asked to enter their go and then player 2 will be asked
# The result will then be displayed.

# This function reads the input from the keyboard for the go of player 2
function player1 {
  echo -p "Player 1. please enter your guess: "
  read -s player1
}

# This function reads the input from the keyboard for the go of player 2
function player2 {
  echo -p "Player 2, please enter your guess: "
  read -s player2
}

# This function compares the inputs from the two players and then outputs the
# result
function compare {
  if [[ $player1 == $player2 ]]; then
    echo "Its a Tie"
  elif [[ $player1 ==  "rock" && $player2 == "scissors" ]]; then
    echo "Player 1 Wins"
  elif [[ $player1 == "sissors" && $player2 == "rock" ]]; then
    echo "Player 2 Wins"
  elif [[ $player1 == "scissors" && $player2 == "paper" ]]; then
    echo "Player 1 Wins"
  elif [[ $player1 == "paper" && $player2 == "scissors" ]]; then
    echo "Player 2 Wins"
  elif [[ $player1 == "paper" && $player2 == "rock" ]]; then
    echo "Player 1 Wins"
  elif [[ $player1 = "rock" && $player2 == "paper" ]]; then
    echo "Player 2 Wins"
  else
    echo "There was an error please try again"
    main
  fi
}

# This function asks the use if they would like to play again and will then
# call the main function of end the script
function playAgain {
  echo "Would you like to play again? (y/n): "
  read play
  if [[ $play == "y" ]]; then
    main
  fi
}

function main {
  player1
  player2
  compare
  playAgain
}

main
