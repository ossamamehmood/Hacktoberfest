#include <iostream>
using namespace std;

// Memo table to store nth fibonacci term
int memo[10000];

// Fibonacci() returns nth term of Fibonacci sequence 
int fibonacci(int n){
    if(memo[n] != 0)    return memo[n];
    if(n == 1)  return 0;
    if(n == 2)  return 1;

    return (memo[n] = fibonacci(n-1) + fibonacci(n-2));
}

int main(){
    int n;
    cout << "Enter length of sequence\n";
    cin >> n;
    
    // Printing each term of the fibonacci sequence
    for(int i = 1;i <= n; i++){
        cout << fibonacci(i) << " ";
    }

    return 0;
}