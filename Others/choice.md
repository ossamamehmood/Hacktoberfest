#include<iostream>
using namespace std;
int main(){
	int ch;
	cout<<"Enter the choice:";
	cin>>ch;
	switch(ch){
		case 0:cout<<"Sunday";
		break;
		case 1:cout<<"Monday";
		break;
		case 2:cout<<"Tuesday";
		break;
		case 3:cout<<"Wednesday";
		break;
		case 4:cout<<"Thursday";
		break;
		case 5:cout<<"Friday";
		break;
		case 6:cout<<"Saturday";
		break;
		default:cout<<"Invalid choice";
	}
	return 0;
}
