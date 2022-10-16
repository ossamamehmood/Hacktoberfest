/* This program is to find that given number is prim or not*/

#include<iostream>
using namespace std;

int main()
{
int no,i;

cout<<"Enter a number";
cin>>no;

for(i=2;i<=no;i++){

if(no%i==0)
{

break;
}

}
if(i==no)
{
cout<<"Number is a prime number";


}
else
{
cout<<"Number is not a prime number";


}



return 0;
}

