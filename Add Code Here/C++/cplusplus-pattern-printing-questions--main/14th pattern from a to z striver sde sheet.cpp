 //14th pattern from a to z striver sde sheet
 
#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    char ch = 'A';
    
    	for(int i = 1;i<=n ;i++)
	{//we need some if else in this case 
	   	for(int j =1;j<=i;j++)
    	{       
    	     cout<<ch<<" ";
    	     ch++;
    	} 
    	//endl for new line after each row completes printing star
    	ch = 'A';
    	cout<<endl;
	}
	// your code goes here
 
	return 0;
}
