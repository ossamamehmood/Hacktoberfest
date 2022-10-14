#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
   float x,y,big;
   cout<<"Enter the Two Numbers :"<<endl;
   cin>>x>>y;

   big=(x>y?x:y);
   cout<<"Larger number is :"<<big<<endl;
return 0;
}