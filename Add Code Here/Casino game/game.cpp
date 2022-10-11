/*
###############################################
            Casino game using C++

@author: Tapati
Student at GCETTB
###############################################
*/

#include <iostream>
#include <string>

#include "game.h"

using namespace std;

void Game::setbetAmount(int bamount)
{
    this->betAmount = bamount;
}

void Game::setdice(int dice)
{
    this->dice = dice;
}

void Game::setguessNumber(int gnumber)
{
    this->guessNumber = gnumber;
}

void Game::setplayerName(string pname)
{
    this->playerName = pname;
}

void Game::settotalAmount(int tamount)
{
    this->totalAmount = tamount;
}

void Game::rules()
{
    cout << "\n\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "\t\t#################                                             ######################" << endl;
    cout << "\t\t=================✨ ✨ CASINO NUMBER GUESSING GAME RULES ✨ ✨======================" << endl;
    cout << "\t\t#################                                             ######################" << endl;
    cout << "\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n" << endl;
    cout << "\t--------------------------------------------------------------------\n" << endl;
    cout << "\t 👉1. Choose a number between 1 to 10 \t" << endl;
    cout << "\t 👉2. Winner gets 5 times of the money he/she bet \t" << endl;
    cout << "\t 👉3. Wrong bet, and you will loose the money you bet\n" << endl;
    cout << "\t--------------------------------------------------------------------" << endl;
}

void Game::getBettingAmount()
{
    do
    {
        cout << "Hey, " << this->playerName << " please enter your betting amount:💰 Rs.";
        cin >> this->betAmount;

        if(this->betAmount > this->totalAmount)
        {
            cout << "\n🚫🚫🚫🚫" << endl;
            cout << "\nBetting balance can't be more than your current balance!😔😔\n" << endl;
            cout << "👉Re-enter your betting amount \n" << endl;
        }
    }while(this->betAmount > this->totalAmount);
}

void Game::getGuessingNumber()
{
    do
    {
        cout << "🎀Guess any number between 1 to 10: ";
        cin >> this->guessNumber;

        if(this->guessNumber <= 0 || this->guessNumber > 10)
        {
            cout << "\n🚫🚫🚫🚫" << endl;
            cout << "\nYour guessing number should be between 1 to 10 😕\n" << endl;
            cout << "👉Please re-enter your guessing number \n" << endl;
        }
    }while(this->guessNumber <= 0 || this->guessNumber > 10);
}

void Game::play()
{
    char choice;
    srand(time(0));

    cout << "\t\t###################################################################################" << endl;
    cout << "\t\t#############                                                      ################" << endl;
    cout << "\t\t############################ 🎀🎀    WELCOME    🎀🎀 ##############################" << endl;
    cout << "\t\t#############                           TO                         ################" << endl;
    cout << "\t\t#############                 🎲  CASINO   WORLD  🎲               ################" << endl;
    cout << "\t\t#############                                                      ################" << endl;
    cout << "\t\t###################################################################################\n\n" << endl;

    cout << "Please tell what's your name?😊 : " << endl;
    getline(cin, this->playerName);
    cout << "\n" << "Hello✋ " << this->playerName << "\n" << "Enter the starting amount💰 to start the game : Rs.";
    cin >> this->totalAmount;

    cout << "\n\t🔖🔖🤞Let's start................\n" << endl;
    cout << "\tRead all the rules carefully-------------" << endl;

    rules();
    do
    {
        cout << "\n\nYour current balance is💰: Rs." << this->totalAmount << "\n" << endl;

        getBettingAmount();
        getGuessingNumber();

        this->dice = rand()%10 + 1;
        if(this->dice == this->guessNumber)
        {
            cout << "\n\t\t🎇🎈🎊🎈🎇\t\t" << endl;
            cout << "\t ***🤟💐 CONGRADULATIONS 💐🤟*** \t\n" << "You are in luck!!🏆" << endl;
            cout << "\n🏅🏅You have won 💰Rs. " << this->betAmount * 5 << endl;
            this->totalAmount = this->totalAmount + this->betAmount * 5;
        }
        else
        {
            cout << "\n\tOpps!  😟😟Better luck, next time!!!\n" << endl;
            cout << "🙂You have lost Rs." << this->betAmount << endl;
            this->totalAmount = this->totalAmount - this->betAmount;
        }

        cout << "\nThe winning number is: " << dice << "\n" << endl;
        cout << this->playerName << " your current balance is: " << this->totalAmount << endl;

        if(this->totalAmount == 0)
        {
            cout << "\n\tYou have no sufficient balance💰 to play further🙂\t\n" << endl;
            break;
        }
        cout << "\n\n\t*** >> Do you want to play again(Y/N)???😇\t" << endl;
        cin >> choice;

    }while(choice == 'Y' || choice == 'y');
    cout << "\n\t😇Thanks for playing the game. Your balance is 💰: Rs." << this->totalAmount << endl;

}