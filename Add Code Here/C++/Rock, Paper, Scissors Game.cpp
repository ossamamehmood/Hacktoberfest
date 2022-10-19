#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int getRan();
int userCh();
void winner(int, int);
int main()
{
    int userChoice = userCh();
    int compChoice = getRan();
    if(userChoice == compChoice)
    {
        cout << "Both players have entered the same choice\nNo winner was decided" << endl;
    } 
    else
    winner(compChoice, userChoice);
}
//Function to input computer's choice
int getRan()
{
   srand(time(0));
    int rn = rand() % 3 + 1;
    if (rn == 1) cout << "Computer has chosen Rock" << endl;
    if (rn == 2) cout << "Computer has chosen Paper" << endl;
    if (rn == 3) cout << "Computer has chosen Scissors" << endl;
    return rn;
}
//Function to input user's choice
int userCh()
{
    int c;
    cout << "Enter 1 for Rock, 2 for Paper, 3 for Scissors:" << endl;
    cin >> c;
    while(!(c>=1&&c<=3))
    {
    	cout<<"Invalid choice..."<<endl<<"Enter again:"<<endl;
    	cin>>c;
	}
    if (c == 1) cout << "You have chosen Rock" << endl;
    if (c == 2) cout << "You have chosen Paper" << endl;
    if (c == 3) cout << "You have chosen Scissors" << endl;
    return c;
}
//Function to determine the winner
void winner(int c, int u)
{
    cout << endl;
    if (c == 1 && u == 3) cout << "Computer is the winner" << endl;    //Computer's choice is Rock & user's choice is Scissors
    if (c == 3 && u == 2) cout << "You are the winner" << endl;        //Computer's choice is Scissors & user's choice is Paper
    if (c == 2 && u == 1) cout << "Computer is the winner" << endl;    //Computer's choice is Paper & user's choice is Rock
    if (c == 3 && u == 1) cout << "You are the winner" << endl;        //Computer's choice is Scissors & user's choice is Rock
    if (c == 2 && u == 3) cout << "Computer is the winner" << endl;    //Computer's choice is Paper & user's choice is Scissors
    if (c == 1 && u == 2) cout << "You are the winner" << endl;        //Computer's choice is Rock & user's choice is Paper
}