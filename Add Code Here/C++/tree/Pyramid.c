//C program to print the pyramid pattern
#include <stdio.h>
#include <conio.h>

int main()
{
    int i,j;
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=9; j++)
        {
            if(j>=6-i && j<=4+i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }
    getch();
}
