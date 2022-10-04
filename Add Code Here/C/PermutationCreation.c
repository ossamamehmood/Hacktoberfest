#include <stdio.h>
int main(void) {
	int t;
	scanf("%d",&t);
	l1: while (t--)
    {
        long long x ,i ;
        scanf("%lld",&x);
        if(x<=3)
        {
            printf("-1\n");
            goto l1;
        }
        else if(x==4)
        {
            printf("3 1 4 2\n");
            goto l1;
        }
        
        else
        {
        for(i=1;i<=x;i=i+2)
        printf("%lld ",i);
        for(i=2;i<=x;i=i+2)
        printf("%lld ",i);
        }
        printf("\n");
    }
	return 0;
}

