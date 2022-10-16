#include<stdio.h>
int size,n;
void heapify(int A[],int i)
{
  int l,r,largest,t;
  l=2*i;
  r=(2*i)+1;
  if(l<=size && A[l]>A[i])
      largest=l;
  else
      largest=i;
  if(r<=size && A[r]>A[largest])
      largest=r;
  if(largest!=i)
  {
      t=A[i];
      A[i]=A[largest];
      A[largest]=t;
      heapify(A,largest);
  }
}
void build_max_heap(int A[])
{
     int i;
     size=n;
     for(i=(n/2);i>=1;i--)
	heapify(A,i);
}
void heapsort(int A[])
{
    int i,t;
    build_max_heap(A);
    for(i=size;i>=2;i--)
    {
	t=A[1];
	A[1]=A[i];
	A[i]=t;
	size--;
	heapify(A,1);
    }
}
int main()
{
     int A[20],i;
     printf("enter size :");
     scanf("%d",&n);
     printf("\n enter array elements ");
     for(i=1;i<=n;i++)
	scanf("%d",&A[i]);
     heapsort(A);
     printf("\n After sort");
     for(i=1;i<=n;i++)
	printf("\n %d",A[i]);
}
