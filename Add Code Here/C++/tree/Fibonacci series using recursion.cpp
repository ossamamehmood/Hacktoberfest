#include <iostream>
using namespace std;

// fibonacci series using recursion
int fibonacci(int n){
    if (n<=1)
        return n;
    else 
        return(fibonacci(n-1) + fibonacci(n-2));
    }

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    
    int fib = fibonacci(n);
    cout << "Fibonacci Series output: "<<fib<<endl;
    return 0;
}
