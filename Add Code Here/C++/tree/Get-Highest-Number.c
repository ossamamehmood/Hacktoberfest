#include<stdio.h>  

void main ()  
{  
    int arr[100],i,n,largest,sec_largest;  
    printf("Enter the size of the array?");  
    scanf("%d",&n);  
    printf("Enter the elements of the array?");  
    for(i = 0; i<n; i++)  
    {  
        scanf("%d",&arr[i]);  
    }  
    largest = arr[0];  
      
    for(i=0;i<n;i++)  
    {  
        if(arr[i]>largest)  
        {
            largest = arr[i];  
        }
        else if (arr[i]!=largest)  
        {
           
        }  
    }  
    printf("largest = %d",largest);  
      
} 
