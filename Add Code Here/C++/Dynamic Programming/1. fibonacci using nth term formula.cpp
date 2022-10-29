#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
double phi,nphi;
/*  using nth term formula*/

/* if  n>=0  ans=phi^n/sqrt(5);
   else ans=-phi^-n/sqrt(5)  */
double fib(double n)
{
   return round(pow(phi,n)/ sqrt(5)) ;
}

int main()
{
    phi=(1+sqrt(5))/2;
    nphi=(1-sqrt(5))/2;
     double n;
     while(1){
        cin>>n;
        cout<<fib(n)<<endl;
     }
 return 0;
}

