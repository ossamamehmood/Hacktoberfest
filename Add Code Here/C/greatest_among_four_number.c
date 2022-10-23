#include <stdio.h>

int greatest(int, int, int, int);

int greatest(int a, int b, int c, int d)
{
    if( a>b && a>c && a>d )
      {
        return a;
     }
    else if( b>a && b>c && b>d )
    {
     return b;
    }
    else if( c>a && c>b && c>d)
    {
        return c;
    }
    else {
        return d;
    }


}

int main( int p, int q, int r, int s, int great )  
{
   
    printf("Enter four numbers : \n");
    scanf("%d %d %d %d", &p, &q, &r, &s);
    great = greatest(p, q, r, s);
    printf("Greatest is : %d \n", great);
}
