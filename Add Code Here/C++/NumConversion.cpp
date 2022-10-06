#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;
int main()
{	int ch;
	cout<<"1.)To convert Decimal to Binary \n2.)To convert Binary to Decimal";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
	case 1: int n;
			cout<<"Enter a number in decimal form: ";	
			cin>>n;
			long dig;
			while(n!=0)
			{
			dig=n%2;
			n/=2;
			cout<<dig;
			}
	     	break;
	case 2: {
			long x;
			cout<<"Enter a number in binary form: ";
			cin>>x;	
			int rem,sum=0,i=0;
			while(x!=0)
			{
		
			rem=x%10;
			x=x/10;
			sum+=rem*pow(2,i);
			i++;
			}
			cout<<"\nDecimal form of the given number is: "<<sum;
	    	break;
	        }
	default: cout<<"\nWrong choice entered!!";
	}
	getch();
	return 0;			
}
