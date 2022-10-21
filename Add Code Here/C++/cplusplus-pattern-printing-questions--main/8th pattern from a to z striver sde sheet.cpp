 //8th pattern from a to z striver sde sheet
//upward pyramid
#include <iostream>
using namespace std;

int main() {
    const int n = 5;
	// your code goes here
	//use two for loops outside one will iterate for each row and inside for loop will iterate foe each column 
	for(int i = n;i>=1 ;i--)
	{//we need some if else in this case 
	   	for(int j =1;j<=2*n-1 ;j++)
    	{   
    	    if(j>=n-(i-1)&&j<=n+(i-1))
    	    {
    	        cout<<"*";
    	    }
    	    else 
    	    cout<<" ";
    	    
    	} 
    	//endl for new line after each row completes printing star
    	cout<<endl;
	}
	return 0;
}
