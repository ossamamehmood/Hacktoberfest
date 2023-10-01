#include<stdio.h>
int main(int argc, char const *argv[])
{
    int p,c,m,e,h,total;
    float per;
    printf("Enter your marks in Physics: ");
    scanf("%d",&p);
    printf("Enter your marks in MAth: ");
    scanf("%d",&m);
    printf("Enter your marks in Chemistry: ");
    scanf("%d",&c);
    printf("Enter your marks in English: ");
    scanf("%d",&e);
    printf("Enter your marks in Hindi: ");
    scanf("%d",&h);
    total=p+c+m+e+h;
    per=total/5.0;
    if (per>90)
    {
        printf("A+ Grade");
    }
    else if (per>=80&&per<=89)
    {
        printf("A Grade");
    }
    else if (per>=70&&per<=79)
    {
        printf("B Grade");
    }
    else if (per>=60&&per<=69)
    {
        printf("B+ Grade");
    }
    else if (per>=50&&per<=59)
    {
        printf("C Grade");
    }
    else if (per>=40&&per<=49)
    {
        printf("D Grade");
    }
    else if (per>=0&&per<=39)
    {
        printf("You are fail");
    }
    
    
    return 0;
}
