// Karatsuba algorithm for two numbers multiplication
// It will work fine for upto 15 digit 2 numbers ...answer 30 digits
#include<stdio.h>
#define lli long long int
long long int power(long long int n)
{
    long long int x=n,ans=1;
    while(x--)
    {
        ans*=10;
    }
    return ans;
}
long long int numlen(long long int t)
{
    long long int x,count=0;
    x=t;
    while(x)
    {
        x/=10;
        count++;
    }
    if(count==0)
        return count+1;
    return count;
}
long long int karatsuba(long long int x,long long int y)
{
    long long int n1,n2,n,x1,x2,y1,y2,u,v,w,z,p;
    n1=numlen(x);
    n2=numlen(y);
    n=n1>n2?n1:n2;
    if(n==1)
        return x*y;
    else 
    {
        n=n+n%2;
        x2=x%power(n/2);
        y2=y%power(n/2);
        x1=x/power(n/2);
        y1=y/power(n/2);

        u=karatsuba(x1,y1);
        v=karatsuba(x2,y2);
        w=karatsuba((x1-x2),(y1-y2));
        z=u+v-w;
        p=u*power(n)+z*power((n+1)/2)+v;
        if(n>=10)
        {
            p=v%power(n/2);
            z+=v/power(n/2);
            printf("%lld",u+(z/power(n-n/2)));  
            long long int z_=z%power(n/2);
            if(numlen(z_)<n/2)
            {
                for(int i=0;i<n/2-numlen(z_);i++)
                {
                    printf("0");
                }
            } 
            printf("%lld",z_);  
            if(p==0)
                while(n>2)
                {
                    printf("0");
                    n-=2;
                }
            else if(numlen(p)<n/2)
            {
                for(int i=0;i<n/2-numlen(p);i++)
                {
                    printf("0");
                }
            }    
        }
    }
    return p;
}
int main()
{
    long long int x,y;
    printf("Enter first number : ");
    scanf("%lld",&x);
    printf("Enter second number : ");
    scanf("%lld",&y);
    printf("The ans = ");
    printf("%lld\n",karatsuba(x,y));
   return 0;
}