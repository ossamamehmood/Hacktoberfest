// password strength checker full project in C++

#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>
#include <string.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void go_to_xy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void main_border(int x = 0, int y = 0){
	char v = 186, h = 205, br = 188, bl = 200, tr = 187, tl = 201;
    int width = 30, height = 3;

    for(int i = 1; i <= height; i++){

		for(int j = 1; j <= width; j++){

	    	go_to_xy(j + x, i + y);
	    	if(i == 1 && j == 1) cout << tl;
			else if(i == height && j == 1) cout << bl;
	    	else if(i == 1 && j == width) cout << tr;
			else if(i == height && j == width) cout << br;
			else if(i == 1 || i == height) cout << h;
			else if(j == 1 || j == width) cout << v;
		}

	}

}

int main(){
    srand((unsigned) time(NULL));

	system("cls");

 	char op, password[21];
 	int length;

	do{
		system("cls");

		cout << "±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±" << endl << endl;
		cout << "\t\t  ±±±±± " << endl;
		cout << "\t\t  ±   ± " << endl;
		cout << "\t\t±±±±±±±±±" << endl;
		cout << "\t\t±±±± ±±±±" << endl;
		cout << "\t\t±±±±±±±±±" << endl << endl;

		cout << "     CHECK  YOUR  PASSWORD  STRENGTH      " << endl;
		cout << "±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±" << endl << endl;

		cout << endl << "\tEnter password: ";
		cin >> password;

		char pass[21] = "";

		int excess = strlen(password) - 6, baseScore = 50;
		int numUpper = 0, numSymbol = 0, numLower = 0, numDigit = 0;
		int bonusExcess = 3, bonusUpper = 4, bonusNumbers = 5, bonusSymbols = 5;
		int bonusCombo = 0, bonusFlatLower = 0, bonusFlatNumber = 0;

		int i;
		for(i = 0; i < strlen(password); i++){
			if(password[i] >= 48 && password[i] <= 57){    // checking digits 0-9
				numDigit++;
			}

			if(password[i] >= 97 && password[i] <= 125){     // checking lowercase a-z
				numLower++;
			}

			if(password[i] >= 65 && password[i] <= 90){    // checking uppercase letter A-Z
				numUpper++;
			}

			if(password[i] >= 33 && password[i] <= 47){    // checking special characters
				numSymbol++;
			}
		}

		if(numUpper > 0 && numDigit > 0 && numSymbol > 0){
			bonusCombo = 25;
		}

		else if((numUpper > 0 && numDigit > 0) || (numUpper > 0 && numSymbol > 0) || (numDigit > 0 && numSymbol > 0)){
			bonusCombo = 15;
		}

		int score = baseScore + (excess * bonusExcess) + (numUpper * bonusUpper) +
				(numDigit * bonusNumbers) + (numSymbol * bonusSymbols) +
				bonusCombo + bonusFlatLower + bonusFlatNumber;

		go_to_xy(8, 14);
		cout << "Checking password strength....";
		go_to_xy(8, 15);
		for(int i = 0; i < 27; i++){
			cout << (char)176;
			Sleep(100);
		}

		main_border(7, 17);

		go_to_xy(10, 19);
		if(score < 50){
			cout << "Password Status: Weak";
		}

		else if(score >= 50 && score < 75){
			cout << "Password Status: Average";
		}

		else if(score >= 75 && score < 100){
			cout << "Password Status: Strong";
		}

		else if(score >= 100){
			cout << "Password Status: Secure";
		}

		go_to_xy(9, 23); cout << "Do you want to check more (y/n): ";
		op = getch();
	}while(op=='y' || op=='Y');

    return 0;
}