/**
 * @file snake_water_gun.c
 * @author KUSHAGRA JAISWAL
 * @copyright Copyright (c) 2022
 */

/* Snake, Water, Gun OR Rock, Paper, Scissor is a  game most of us have played during school time.
    Write a C program Capabale of playing this game with you.
    Your program should be able to return the result after you choose snake / water or gun.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// these are the header files.

int snakegunwater(char your_choice, char computer_choice)
// function defination and decleration
{
    // condition for draw.
    if (your_choice == computer_choice)
    {
        return 0;
        // 0 is for draw.
    }

    // Non - Draw Conditions
    if (your_choice == 's' && computer_choice == 'g')
    {
        return -1;
        // -1 if you loose.
    }
    else if (your_choice == 'g' && computer_choice == 's')
    {
        return 1;
        // if you win.
    }

    else if (your_choice == 's' && computer_choice == 'w')
    {
        return 1;
    }
    else if (your_choice == 'w' && computer_choice == 's')
    {
        return -1;
    }
    else if (your_choice == 'g' && computer_choice == 'w')
    {
        return -1;
    }
    else if (your_choice == 'w' && computer_choice == 'g')
    {
        return 1;
    }
}

int main()
{
    // main function

    printf("\n*******Welcome To Snake, Water & Gun Game !*********\n");
    // printf is a function which is use to print any text.
    // giving a message in terminal.

    printf("---------------------------------------------------\n");
    // for some spacing in terminal.

    int random_number;
    char your_choice;
    char computer_choice;
    char c = 'y';
    // declearing variables.

    srand(time(0));
    // this line will help to generate different randon numbers.

    random_number = rand() % 100 + 1;
    // here we generate a random number using rand() function after that
    // we are dividing it with 100 and take the remender so basicall this (rand() %100 + 1)
    // will only generate random numbers between 1 - 100.

    // printf("the number is : %d\n", random_number);
    // printing the generated random number

    if (random_number < 33)
    {
        computer_choice = 's';
    }

    if (random_number > 33 && random_number < 66)
    {
        computer_choice = 'w';
    }

    else
    {
        computer_choice = 'g';
    }

    printf("\nRules for Playing The Game!\n\n");
    printf("\n1. Every time computer will choose Snake, Water, Gun anyone from it.\n");
    printf("\n2. You have to choose your choice between Snake, Water, Gun.\n");
    printf("\n3. If there is Snake and Water then Snake will drink all the water and Snake wins .\n");
    printf("\n4. If there is Snake and Gun then Gun will Shoot the Snake and Snake dies and Gun wins .\n");
    printf("\n5. If there is Gun and Water then Gun will sink into the Water and Water wins .\n");
    printf("\n6. If both choose same option game will be draw .\n");
    printf("\n7. I hope you will Enjoy it alot!\n\n");
    // rulees for playing this game.

    printf("---------------------------------------------------\n\n");

    printf("Write (S) for SNAKE\n");
    printf("Write (W) for WATER\n");
    printf("Write (G) for GUN\n");
    printf("\nEnter your choice: ");
    scanf("%c", &your_choice);
    // user input.

    int result = snakegunwater(your_choice, computer_choice);
    // function calling.

    printf("\n You Choose %c and Computer Choose %c \n", your_choice, computer_choice);
    // shows the selecter options.

    if (result == 0)
    {
        printf("\n Game Draw\n\n");
    }

    else if (result == 1)
    {
        printf("\n You Win\n\n");
    }

    else
    {
        printf("\n You Loose\n\n");
    }

    printf("\n Enter 'y' to play again and 'n' to exit : ");
    scanf("%c", &c);

    return 0;
}