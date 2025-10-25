//Program to print 1st N natural numbers and calculate their sum and average
#include <stdio.h>
int main() {
    long int N, i;
    long int sum = 0;
    double average;

    // Ask user for input
    printf("Enter a positive integer: ");
    scanf("%ld", &N);

    // Print the first N natural numbers
    printf("The first %d natural numbers are:\n", N);
    for(i = 1; i <= N; i++) {
        printf("%ld\n", i);
        sum += i;
    }

    // Calculate average
    average = (double)sum / N;
    
    // Print sum and average
    printf("Sum of the first %ld natural numbers is: %ld\n", N, sum);
    printf("Average of the first %ld natural numbers is: %.2lf\n", N, average);

    return 0;
}
