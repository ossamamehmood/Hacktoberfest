#include<stdio.h>
#include<conio.h>
int main()
{
    int num, rem, arr[10], i=0, count=0;
    printf("Enter the Number: ");
    scanf("%d", &num);
    while(num!=0)
    {
        rem = num%10;
        arr[i] = rem;
        num = num/10;
        i++;
        count++;
    }
    printf("\nReverse = ");
    for(i=0; i<count; i++)
        printf("%d", arr[i]);
    getch();
    return 0;
}
