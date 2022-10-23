#include<iostream>
using namespace std;
int factorial(int n)
{
    if (n<=1)
    {
        return 1;
    }
return n * factorial(n-1);
}
int fib(int n)
{
    if (n<2)
    {
        return n;
    }
return fib(n-2) + fib(n-1); // this also can be return in else form rather than return form
}


/* STEP BY STEP FIBONACCI
fib(5) + fib(4) + fib(3)
fib(3) + fib(2)
fib(2)+ fib(3) + fib(2) + fib(3)*/


/*STEP BY STEP

factorial(4) = 4 * factorial(3)
factorial(4) = 4 * 3 * factorial(2)
factorial(4) = 4 * 3 * 2 * factorial(1)
factorial(4) = 4 * 3 * 2 * 1 
*/

int main(){
// factorial of a number
//6! = 6*5*4*3*2*1 = 720
// 0! = 1 by definition
//1! = 1 by definition
//n! = n*(n-1)!
int a;
cout<<"enter a number"<<endl;
cin>>a;
//cout<<"factorial of a is "<<factorial(a)<<endl;
cout<<"the term in fibonacci series at position  "<<a<<"is"<<fib(a)<<endl;

return 0;
}