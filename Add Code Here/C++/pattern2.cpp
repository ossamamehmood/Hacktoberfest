#include<iostream>
#include<conio.h>
using namespace std;
int main()
{	int rows;
	cout<<"Enter number of rows::";
	cin>>rows;
	for(int i=1;i<=rows;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	getch();
	return 0;
}
