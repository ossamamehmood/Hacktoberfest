#include<iostream>
using namespace std;

int main()

{
cout<<"Hello, Welcome Here"<<endl;
cout<<"Please Enter Your Marks"<<endl;
	int maths,phy,chem,bio,english,music,fine,sum;
	float per;
	cout<<"Maths=";
	cin>>maths;
	
	cout<<"Physics=";
	cin>>phy;
	
	cout<<"Chemistry=";
	cin>>chem;
	
	cout<<"Biology=";
	cin>>bio;
	
	cout<<"English=";
	cin>>english;
	
	cout<<"Music=";
	cin>>music;
	
	cout<<"Fine Arts= ";
	cin>>fine;
	
	sum= maths+phy+chem+bio+english+music+fine;
	cout<<"\nTotal Marks="<<sum<< endl;
	if(sum >=201)
	   cout<<"Congratulations, you have cleared the exam";
	else
	   cout<<"Sorry, Better Luck For Next Time";
	per=sum*100/700;
	cout<<"\nYour Percentage-:/n%"<<per;
}
