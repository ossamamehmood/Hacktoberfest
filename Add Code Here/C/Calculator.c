// Command-Line Calculator in C

#include <stdio.h>

int main()
{
    // Declare variables to store the operator and two numbers, as well as the result of the calculation.
    char operator;
    double num1, num2, result;

    // Prompt the user to enter two numbers.
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2); // Read two numbers entered by the user.

    // Prompt the user to enter an operator (+, -, *, /).
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator); // Read the operator character entered by the user.

    // Use a switch statement to perform the operation based on the operator entered.
    switch (operator)
    {
    case '+':
        result = num1 + num2; // Addition
        break;
    case '-':
        result = num1 - num2; // Subtraction
        break;
    case '*':
        result = num1 * num2; // Multiplication
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2; // Division (avoid division by zero)
        }
        else
        {
            printf("Error: Division by zero is not allowed.\n");
            return 1; // Exit with an error
        }
        break;
    default:
        printf("Error: Invalid operator.\n");
        return 1; // Exit with an error code
    }

    // Display the result of the calculation with two decimal places.
    printf("Result: %.2lf\n", result); // To format the output in a specific way.

    return 0; // Executed successfully
}
