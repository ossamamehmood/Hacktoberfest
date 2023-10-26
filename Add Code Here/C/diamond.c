#include <stdio.h>
 
int main()
{
    int i,j,n;
    char ch;
 
    printf("Enter number of rows: ");
    scanf("%d%c",&n,&ch);
    printf("Enter the symbol: ");
    ch=getchar();
  
 
 
    for(i=1;i<=n;i++)
    {
	    for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
 
        for(j=1;j<=i*2-1;j++)
                
        {
            printf("%c",ch);
        }
        printf("\n");
	    
    }            
               
	for(i=n-1;i>0;i--)
    {
	    for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=i*2-1;j++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }  
 
 
    return 0;
}
