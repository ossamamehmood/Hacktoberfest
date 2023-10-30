#include<stdio.h>
int main() {
    int i,j,k,p;
    
    for(i=1;i<=4;i++)
    {
        p=1,k=1;
        for(j=1;j<=7;j++)
        
        if(j<=5-i || j>=3+i)//use or operator
        {
        printf("%d",k);
        p=k;//data ko copy kar diya increase ho gya 
        j<4 ? k++:k--;
        }
        
        else
        {
            printf(" ");
            k=p; //data ko vapis copy kara diya
        }
        printf("\n");
    }
    return 0;
