#include<iostream>
using namespace std;

int main(){
	char a[10];
	
	cin>>a;
	int b0,b1,b3,b4,b5,b7,b8;

	b0=a[0];
	b1=a[1];
	b3=a[3];
	b4=a[4];
	b5=a[5];
	b7=a[7];
	b8=a[8];

	if((b0+b1-96)%2!=0 || (b3+b4-96)%2!=0 || (b4+b5-96)%2!=0 || (b7+b8-96)%2!=0  || a[2]=='A' || a[2]=='E' || a[2]=='I' || a[2]=='O' || a[2]=='U' || a[2]=='Y' ){
		cout<<"invalid";
	}
  
	else{
		cout<<"valid";
	}

}
