//2nd pattern from a to z striver sde sheet
#include <iostream>
using namespace std;

int main() {
    const int n = 5;
	// your code goes here
	//use two for loops outside one will iterate for each row and inside for loop will iterate foe each column 
	for(int i = 1;i<=n ;i++)
	{
	   	for(int j =1;j<=i ;j++)
    	{
    	    cout<<j<<" ";
    	} 
    	//endl for new line after each row completes printing star
    	cout<<endl;
	}
	return 0;
}
