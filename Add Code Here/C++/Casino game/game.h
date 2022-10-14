/*
###############################################
            Casino game using C++

@author: Tapati
Student at GCETTB
###############################################
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Game
{
    public:
        void rules();
        void play();
        void getBettingAmount();
        void getGuessingNumber();

        void setbetAmount(int bamount);
        void setdice(int dice);
        void settotalAmount(int tamount);
        void setguessNumber(int gnumber);
        void setplayerName(string pname);
    private:
        int betAmount, dice, totalAmount, guessNumber;
        string playerName;
};

#endif