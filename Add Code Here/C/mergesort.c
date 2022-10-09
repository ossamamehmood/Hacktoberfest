#include<stdio.h>
#include<conio.h>
void merge(int a[],int beg,int mid,int end)
{
    int i,j,k;
    int n1=mid-beg+1;
    int n2=end-mid;
    int la[n1],ra[n2];
    for(i=0;i<n1;i++)
    {
        la[i]=a[beg+i];
    }
    for(j=0;j<n2;j++)
    {
        ra[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=beg;
        while (i < n1 && j < n2)    
    {    
        if(la[i] <= ra[j])    
        {    
            a[k] = la[i];    
            i++;    
        }    
        else    
        {    
            a[k] = ra[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = la[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = ra[j];    
        j++;    
        k++;    
    }  
}
void mergesort(int a[],int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
int main()
{
    int n,a[50],i;
    printf("Enter the number of elements in Array : ");
    scanf("%d",&n);
    printf("Enter the value of each elementin Array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Before Sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nAfter sorting : \n");
     for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

}