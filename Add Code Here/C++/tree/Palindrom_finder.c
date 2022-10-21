#include <stdio.h>
#include <stdlib.h>
/*
1. user enter a number
2. divide in to 10 potions and store in an array;
3. get the reverse array of it
4. then compare the 2 int array number by number, if any of it in equal, break the loop
*/
int main()
{
    char number[100];
    printf("Enter a number: ");
    scanf("%s", number);

    int count = 0;
    while(number[count] != '\0'){
        count++;
    }

    for(int i=0; i<count; i++){
        printf("%c", number[i]);
    }
    printf("\n");

    // reverse number
    char reverseNumber[count];
    int count_R = count;

    for(int i=0; i<count; i++){
        reverseNumber[--count_R] = number[i];
    }

    for(int i=0; i<count; i++){
        printf("%c", reverseNumber[i]);
    }
    printf("\n");

    //comparing 2 arrays
    int flag = 0;

    for(int i=0; i<count; i++){
        if(number[i] != reverseNumber[i]){
           flag = 1;
           break;
        }
    }

    if(flag == 1){
        printf("They are NOT Palindrome \n");
    }else{
        printf("They are Palindrome \n");
    }

    return 0;
}
