#include<iostream>
using namespace std;
int main(){
	int x,y;
	cout<<" enter total no, of units"<<endl;
	cin>>x;
	if(x<=100){
		y=x*5;
	}
	else if(x>100 && x<=200){
		y=x*10;
	}
	else if(x>200 && x<=300){
		y=x*15;
	}
	else if(x>300){
		y=x*20;
	}
	cout<<"total bill to be paid"<< y <<endl;
}
