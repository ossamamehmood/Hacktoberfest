#include <bits/stdc++.h>
using namespace std;

int main(){
	int start, end;
	
	cout << "# Welcome to the Guess The Number Game #" << endl;
	
	cout << "Choose your number range" << endl;
	cout << "From : ";
	cin >> start;
	cout << "To : ";
	cin >> end;
	
	// check if the range (start == end)
	if(start == end){
		cout << "Imagine playing guess the number from " << start << " to " << end;
		return 0;
	}
	
	srand((int)time(0));
	int randnum = (rand() % end) + start;
	
	system ("CLS"); // clear console

	int guess; int test = 1;
	cout << "Guess the number : ";
	cin >> guess;
	
	while(guess != randnum){
		if(guess > randnum){
			cout << "The number is lower than your answer" << endl;
		} else {
			cout << "The number is higher than your answer" << endl;
		}
	cout << "Guess the number : ";
	cin >> guess;
	test++;
	}
	
	system ("CLS"); // clear console
	cout << "Congratulations🎉, the number is " << randnum << " you have tried " << test << " times";
	
}
