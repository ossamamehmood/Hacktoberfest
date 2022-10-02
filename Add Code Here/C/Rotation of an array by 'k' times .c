//Left - Shifting the array by 'k' times

#include <stdio.h>

int swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b= temp;
}

void main()
{   
    int i;
    int a[5] = {1,2,3,4,5};
    int k;
    
    printf ("Number of times you want the array to be left - rotated: ");
    scanf ("%d", &k);
    
    
    
    for (i = k ; i <= (5 - k - 1)/2 + 1 ; i++)
    {
        swap(&a[i] , &a[5 - i + 1]);
        
    }
    for (i = k; i <= 4 ; i++)
    {
        printf ("%d ", a[i]);
    }
    
    printf ("\n");
    
    for (i = 0 ; i <= (k - 1)/2 ; i++)
    {
        swap(&a[i] , &a[k - i - 1]);
    }
    for (i = 0 ; i <= 1 ; i++)
    {
    printf ("%d ", a[i]);
    }
    printf ("\n");
    for (i = 0 ; i <= (4/2) ; i++)
    {
      swap (&a[i] , &a[4-i]);
    }
    for(i = 0 ; i <= 4 ; i++)
    {
        printf ("%d ", a[i]);
    }
}
