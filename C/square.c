#include<stdio.h>
int main()
{
    int i,j,k,l,m,n,o=2,a,b,c,d,g,h;
    printf("enter the last digit of square");
    scanf("%d",&n);
    b=n-1;
    for(i=n;i>=1;i--)
    {
        m=n;
         for(l=1;l<=n-i;l++)
        {
            printf("%d ",m);
            m--;   
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("%d ",i);
        }
        o=i+1;
        for(k=1;k<=n-i;k++)
        {
            printf("%d ",o);
            o++;
        }
        printf("\n");
    }
    for(a=1;a<=b;a++)
    {
        d=n;
        for(c=1;c<=b-a;c++)
        {
            printf("%d ",d);
            d--;
        }   
        for(g=1;g<=2*a+1;g++)
        {
            printf("%d ",a+1);
        }    
        for(h=1;h<=b-a;h++)
        {
            printf("%d ",a+h+1);
        }
        
        printf("\n");
    }
return 0;
}
