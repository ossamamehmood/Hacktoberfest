# include <stdio.h>
# include <math.h>
int main(void)
{
    //Local Declaration
    int n=0,x=0,mid=(n-1)/2,l=0,s=0,r=0;
    //statements
    printf("Enter the size of array.");
    scanf("%d",&n);
    l=n-1;
    int a[n];
    printf("Enter elements in ascending order.\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter element number %d.\n",(i+1));
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched.\n");
    scanf("%d",&x);
        while(r==0)
        {
            mid=(s+l)/2;
        if(x<a[mid])           //checking if element is less than the middle element 
            {l=mid;
            r=0;
            }
            if(x>a[mid])       //checking if the given element is greater than the middle element
            {s=mid;
            r=0;
            }
            if(x==a[mid])      //checking if the given element is equal to the middle lement
            {
                printf("Element %d found at position %d.",x,(mid+1));
                r=1;
            }
            
        }    
    return 0;
}//main