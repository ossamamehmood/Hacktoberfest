#include <stdio.h>

int main()
{
    int date, month, year;
    printf("date : ");
    scanf("%d",&date);
    printf("month : ");
    scanf("%d",&month);
    printf("year : ");
    scanf("%d",&year);
    if((date==20)&&(month==11))
    {
        printf("1");
    }
    else
    {
        printf("-1");
    }
    return 0;
}
