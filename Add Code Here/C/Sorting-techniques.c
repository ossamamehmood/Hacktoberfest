#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
int b[10];
int partition(int a[],int l,int r)
{
    int pivot,start,end,temp;
    pivot=a[l];
    start=l;
    end=r;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            SWAP(a[start],a[end],temp);
    }
    SWAP(a[l],a[end],temp);
    return end;
}
void quick_sort(int a[],int l,int r)
{   int pos;
    if(l<r)
    {
        pos=partition(a,l,r);
        quick_sort(a,l,pos-1);
        quick_sort(a,pos+1,r);
    }

}
void merge(int a[],int l,int mid,int r)
{
    int i,j,k,b[10];
    i=l;
    j=mid+1;
    k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }

    }
    if(i>mid)
    {
        while(j<=r)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
     while(i<=mid)
     {
         b[k]=a[i];
         i++;
         k++;
     }
    }
    for(k=l;k<=r;k++)
        a[k]=b[k];

}
void merge_sort(int a[],int l,int r)
{  int mid,k;
  if(l<r)
  {
      mid=(l+r)/2;
      merge_sort(a,l,mid);
      merge_sort(a,mid+1,r);
      merge(a,l,mid,r);

  }

}
void heapify(int a[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
   int temp;
    if (left < n && a[left] > a[largest])
      largest = left;

    if (right < n && a[right] > a[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      SWAP(a[i], a[largest],temp);
      heapify(a, n, largest);
    }
  }
void heap_sort(int a[],int n)
{ int i,temp;
for (int i = n / 2 - 1; i >= 0; i--)
      heapify(a, n, i);
      for (int i = n - 1; i >= 0; i--) {
      SWAP(a[0], a[i],temp);
      heapify(a, i, 0);
      }
}
void main()
{
   int a[20],n,i,choice=1,ch;
    printf("\nEnter the size of array\t:");
    scanf("%d",&n);
    printf("\n Enter the elements \n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Entered Elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    while(choice=1)
    {
  printf("\n 1.QUICK SORT\n");
  printf(" 2.MERGE SORT\n");
  printf(" 3. HEAP SORT");
  printf("\n 4.EXIT");
  printf("\n Enter your choice:\t");
  scanf("%d",&ch);
  switch(ch)
  {
      case 1:quick_sort(a,0,n-1);
             printf("\nquick sorting....\nsorted array :\n ");
              for(i=0;i<n;i++)
               printf("%d\t",a[i]);
             break;
      case 2:merge_sort(a,0,n-1);
             printf("\nmerge sorting....\nsorted order :\n ");
             for(i=0;i<n;i++)
              printf("%d\t",a[i]);
             break;
     case 3:heap_sort(a,n);
            printf("\nheap sorting....\nsorted order :\n ");
             for(i=0;i<n;i++)
              printf("%d\t",a[i]);
             break;
     case 4:exit(0);
     default:printf("Invalid Input\n");

  }
  //printf("\n Enter 1 for continuing and 0 for exit \t");
  //scanf("%d",&choice);
    }
}
