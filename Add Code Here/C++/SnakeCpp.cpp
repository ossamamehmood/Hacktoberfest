// required header file 
#include <conio.h> 
#include <iostream> 
#include <windows.h> 
using namespace std; 

// height and width of the boundary 
const int width = 80; 
const int height = 20; 

// Snake head coordinates of snake (x-axis, y-axis) 
int x, y; 
// Food coordinates 
int fruitCordX, fruitCordY; 
// variable to store the score of he player 
int playerScore; 
// Array to store the coordinates of snake tail (x-axis, 
// y-axis) 
int snakeTailX[100], snakeTailY[100]; 
// variable to store the length of the sanke's tail 
int snakeTailLen; 
// for storing snake's moving snakesDirection 
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; 
// snakesDirection variable 
snakesDirection sDir; 
// boolean variable for checking game is over or not 
bool isGameOver; 

// Function to initialize game variables 
void GameInit() 
{ 
	isGameOver = false; 
	sDir = STOP; 
	x = width / 2; 
	y = height / 2; 
	fruitCordX = rand() % width; 
	fruitCordY = rand() % height; 
	playerScore = 0; 
} 

// Function for creating the game board & rendering 
void GameRender(string playerName) 
{ 
	system("cls"); // Clear the console 

	// Creating top walls with '-' 
	for (int i = 0; i < width + 2; i++) 
		cout << "-"; 
	cout << endl; 

	for (int i = 0; i < height; i++) { 
		for (int j = 0; j <= width; j++) { 
			// Creating side walls with '|' 
			if (j == 0 || j == width) 
				cout << "|"; 
			// Creating snake's head with 'O' 
			if (i == y && j == x) 
				cout << "O"; 
			// Creating the sanke's food with '#' 
			else if (i == fruitCordY && j == fruitCordX) 
				cout << "#"; 
			// Creating snake's head with 'O' 
			else { 
				bool prTail = false; 
				for (int k = 0; k < snakeTailLen; k++) { 
					if (snakeTailX[k] == j 
						&& snakeTailY[k] == i) { 
						cout << "o"; 
						prTail = true; 
					} 
				} 
				if (!prTail) 
					cout << " "; 
			} 
		} 
		cout << endl; 
	} 

	// Creating bottom walls with '-' 
	for (int i = 0; i < width + 2; i++) 
		cout << "-"; 
	cout << endl; 

	// Display player's score 
	cout << playerName << "'s Score: " << playerScore 
		<< endl; 
} 

// Function for updating the game state 
void UpdateGame() 
{ 
	int prevX = snakeTailX[0]; 
	int prevY = snakeTailY[0]; 
	int prev2X, prev2Y; 
	snakeTailX[0] = x; 
	snakeTailY[0] = y; 

	for (int i = 1; i < snakeTailLen; i++) { 
		prev2X = snakeTailX[i]; 
		prev2Y = snakeTailY[i]; 
		snakeTailX[i] = prevX; 
		snakeTailY[i] = prevY; 
		prevX = prev2X; 
		prevY = prev2Y; 
	} 

	switch (sDir) { 
	case LEFT: 
		x--; 
		break; 
	case RIGHT: 
		x++; 
		break; 
	case UP: 
		y--; 
		break; 
	case DOWN: 
		y++; 
		break; 
	} 

	// Checks for snake's collision with the wall (|) 
	if (x >= width || x < 0 || y >= height || y < 0) 
		isGameOver = true; 

	// Checks for collision with the tail (o) 
	for (int i = 0; i < snakeTailLen; i++) { 
		if (snakeTailX[i] == x && snakeTailY[i] == y) 
			isGameOver = true; 
	} 

	// Checks for snake's collision with the food (#) 
	if (x == fruitCordX && y == fruitCordY) { 
		playerScore += 10; 
		fruitCordX = rand() % width; 
		fruitCordY = rand() % height; 
		snakeTailLen++; 
	} 
} 

// Function to set the game difficulty level 
int SetDifficulty() 
{ 
	int dfc, choice; 
	cout << "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: hard "
			"\nNOTE: if not chosen or pressed any other "
			"key, the difficulty will be automatically set "
			"to medium\nChoose difficulty level: "; 
	cin >> choice; 
	switch (choice) { 
	case '1': 
		dfc = 50; 
		break; 
	case '2': 
		dfc = 100; 
		break; 
	case '3': 
		dfc = 150; 
		break; 
	default: 
		dfc = 100; 
	} 
	return dfc; 
} 

// Function to handle user UserInput 
void UserInput() 
{ 
	// Checks if a key is pressed or not 
	if (_kbhit()) { 
		// Getting the pressed key 
		switch (_getch()) { 
		case 'a': 
			sDir = LEFT; 
			break; 
		case 'd': 
			sDir = RIGHT; 
			break; 
		case 'w': 
			sDir = UP; 
			break; 
		case 's': 
			sDir = DOWN; 
			break; 
		case 'x': 
			isGameOver = true; 
			break; 
		} 
	} 
} 

// Main function / game looping function 
int main() 
{ 
	string playerName; 
	cout << "enter your name: "; 
	cin >> playerName; 
	int dfc = SetDifficulty(); 

	GameInit(); 
	while (!isGameOver) { 
		GameRender(playerName); 
		UserInput(); 
		UpdateGame(); 
		// creating a delay for according to the chosen 
		// difficulty 
		Sleep(dfc); 
	} 

	return 0; 
}
