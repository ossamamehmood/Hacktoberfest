/*
Number guessing game
Created by Dinesh Deore
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int main()
{
    int temp, n, num, count = 0;
    temp = generateRandomNumber(100) + 1;
    printf("Guess the number: ");
    scanf("%d", &num);

    if (num == temp)
    {
        printf("yahhh! you guess the correct number that is %d\n", temp);
    }
    while (num != temp)
    {
        if (num > temp)
        {
            printf("Lower number please: ");
            scanf("%d", &n);
            num = n;
            count++;
        }

        if (num < temp)
        {
            printf("Higher number please: ");
            scanf("%d", &n);
            num = n;
            count++;
        }

        if (num == temp)
        {
            printf("\n-----------------------------------------------------");
            printf("\n yahhh! you guess the correct number that is %d\n\n", temp);

            break;
            count++;
        }
    }

    printf("         number of guesses is: %d", count + 1);
    printf("\n-----------------------------------------------------\n\n");
    return 0;
}
