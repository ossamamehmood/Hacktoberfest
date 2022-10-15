//Program to convert days into month and days

#include <stdio.h>
int main()
{
    int month, day;
    printf("enter the number of days:\t");
    scanf("%d",&day);
    month =  day / 30;
    day = day %30;
    printf("month: %d \ndays: %d", month, day);
}
