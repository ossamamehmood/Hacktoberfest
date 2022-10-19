//Binary to Decimal and Viceversa

#include<iostream>
#include<cmath>
using namespace std;

void conBintoDec(int n){
	int rem, i=0, result=0;

	while(n!=0){
		rem = n%10;
		n /= 10;
		result += rem*pow(2,i);
		i++;
	}
	cout<<result;
}

void conDectoBin(int n){
	int rem[5], i=0;
	
	while(n!=0)
	{
		cout<<"\n Step: "<<i+1;	
		rem[i] =n%2;
		cout<<endl<<"Remainder: "<<rem[i];
		n = n/2;
		cout<<endl<<"Quotient: "<<n<<endl;
		i++;
	}
	
	cout<<"\n The binary equivalent number is : ";
	for (int j=i-1; j>=0; j--)
	{
		cout<<rem[j];
	}
} 

int main()
{
	int dec, bin;
	char ch;
	
	cout<<"Enter (b) for Binary or (d) for Decimal to Convert Vice-Versa: ";
	cin>>ch;
	
	if(ch == 'b' || ch == 'B'){
		cout<<"\n Enter Binary number :";
		cin>>bin;
		conBintoDec(bin);
	}

	else if(ch == 'd' || ch == 'D'){
		cout<<"\n Enter Decimal number :";
		cin>>dec;
		conDectoBin(dec);	
	}
	
	
	return 0;
}
