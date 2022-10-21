//13th pattern from a to z striver sde sheet
//floyd's triangle pattern
#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    int count = 1 ;
    
    	for(int i = 1;i<=n ;i++)
	{//we need some if else in this case 
	   	for(int j =1;j<=i;j++)
    	{       
    	    cout<<count<<" ";
    	    count++;
    	} 
    	//endl for new line after each row completes printing star
    	cout<<endl;
	}
	// your code goes here
 
	return 0;
}
