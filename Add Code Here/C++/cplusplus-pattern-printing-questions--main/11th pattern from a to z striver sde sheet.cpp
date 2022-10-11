//11th pattern from a to z striver sde sheet
//0 1 pattern
#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    
    
    	for(int i = 1;i<=n ;i++)
	{//we need some if else in this case 
	   	for(int j =1;j<=i;j++)
    	{       if((i+j)%2==0)
    	        cout<<" 1";
    	        else 
    	        cout<<" 0";
    	    
    	} 
    	//endl for new line after each row completes printing star
    	cout<<endl;
	}
	// your code goes here
 
	return 0;
}
