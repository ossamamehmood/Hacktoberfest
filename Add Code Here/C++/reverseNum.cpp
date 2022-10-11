#include <iostream>  
using namespace std;  
int reverseNum(int n){
int reverse=0,rem;
  while(n!=0)    
  {    
     rem=n%10;      
     reverse=reverse*10+rem;    
     n/=10;    
  }   
  return reverse;
}
int main()  
{  
int n;
cout<<"Enter a number: ";    
cin>>n;    

 cout<<"Reversed Number: "<<reverseNum(n)<<endl;     
return 0;  
} 
