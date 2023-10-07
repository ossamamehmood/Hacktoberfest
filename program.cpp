// C++ program to check 
// for even or odd 
#include <iostream> 
using namespace std; 

// Returns true if n is 
// even, else odd 
bool isEven(int n) { return (n % 2 == 0); } 

// Driver code 
int main() 
{ 
	int n = 101; 
	if (isEven(n)) 
		cout << "Even"; 
	else
		cout << "Odd"; 

	return 0; 
}
