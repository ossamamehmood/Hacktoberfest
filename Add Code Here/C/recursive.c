#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number = 5; 
    unsigned long long result = factorial(number);
    printf("Factorial of %d is %llu\n", number, result);
    return 0;
}
