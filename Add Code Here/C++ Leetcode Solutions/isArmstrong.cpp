// Armstrong number is a number that is equal to the sum of cubes of its digits. For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.

// Let's try to understand why 371 is an Armstrong number.

// 371 = (3*3*3)+(7*7*7)+(1*1*1)    
// where:    
// (3*3*3)=27    
// (7*7*7)=343    
// (1*1*1)=1    
// So:    
// 27+343+1=371  



#include <iostream>  
using namespace std;  
int main()  
{  
int n,r,sum=0,temp;    
cout<<"Enter the Number=  ";    
cin>>n;    
temp=n;    
while(n>0)    
{    
r=n%10;    
sum=sum+(r*r*r);    
n=n/10;    
}    
if(temp==sum)    
cout<<"Armstrong Number."<<endl;    
else    
cout<<"Not Armstrong Number."<<endl;   
return 0;  
}  
