//A basic program of Finding the maximum of the entered numbers 

//1)Using Functions- using funchions always reduces the execution time( max_of_four) is the function used here
//2)Using ternary Operator- where three( so why it is called as ternary) operands will be present
//syntax of Ternary operator is -  variable = Expression1 ? Expression2 : Expression3



#include <stdio.h>
int max_of_four(int num1,int num2 , int num3 , int num4)
{//using ternary operator 
    int max1=(num1>num2)?num1:num2; 
    int max2 = (num3>num4)?num3:num4;
    return (max1>max2)?max1:max2;
}
int main() {
    int num1,num2,num3,num4;
    printf("Enter number1: ");
    scanf("%d", &num1); 
    printf("Enter number2: ");
    scanf("%d", &num2); 
    printf("Enter number3: ");
    scanf("%d", &num3); 
    printf("Enter number4: ");
    scanf("%d", &num4); 

    int ans = max_of_four(num1,num2,num3,num4);
    printf("The maximum of all the entered num is :%d", ans);

    return 0;
}
