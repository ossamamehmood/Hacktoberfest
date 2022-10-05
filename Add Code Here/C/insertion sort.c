#include<stdio.h>
void main()
{
    int n,i,j,temp;
    printf("enter how long you want aarray\n");
    scanf("%d",&n);
    int arr[n];
    printf("write elemnts of array\n");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&arr[i]);
        
    }  
    
    for(i=1 ; i<n ; i++)
    {
        j=i-1;
        temp=arr[i];
        while(j>-1 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for(i=0 ; i<n ; i++)
    {
        printf("%d",arr[i]);
    }
}    
    
    
    
    
    
    
