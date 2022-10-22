/*7s compliment of a number*/

#include <stdio.h>

int main()
{
    int n = 0, num = 0, temp, flag=1; //n is used to calculate
                    //temp is used to store actual value of n befpre calculation
                    //num stores corresponding 7 n digit number
    while(flag)   //flag is used for infinite loop so program ends when output is completed
    {
        printf("\nEnter a number: ");
        scanf("%d", &n); //takes input 
        if(n < 0) printf("Please enter a positive input:"); //negative input not allowed
        else if(n == 0) 
        {    
            printf("7s complement of 0 is 7"); //for 0 input
            flag = 0;
        }
        else
        {
            temp = n;  //stores actual value of input number
            while(temp > 0) //to calculate corresponding 7 ndigit number
            {
                temp /= 10; //reduces number from tens each loop
                num = num * 10 + 7;  //stores corresponding 7 ndigit number
            }
            if(num - n < 0) printf("Please enter a number less than %d:",num); //answer cant be negative
            else
            {    
                printf("7s complement of %d is %d.\n", n, num - n); //prints the answer
                flag = 0;
            }
        }
    }
}