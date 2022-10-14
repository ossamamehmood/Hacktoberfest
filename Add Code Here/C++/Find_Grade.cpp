#include<iostream>
using namespace std;
int main()
{
     int marks;
     char grade;
     cout<<"Enter the Marks:";
     cin>>marks;

     if(marks>=100){
         cout<<"Marks should not more than 100";
         exit(0);
     }
     else if(marks>79 ) grade='A';
     else if(marks>59) grade='B';
     else if(marks>49) grade='C';
     else if(marks>39) grade='D';
     else grade='E';
     
     cout<<"Your Grade is :"<<grade;
     

return 0;
}