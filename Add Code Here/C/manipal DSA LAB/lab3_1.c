#include<stdio.h>
void insertion(int *arr,int n)
{
    int ind,ele;
    printf("Enter the index where you want to insert ");
    scanf("%d",&ind);
    printf("Enter the element you want to insert");
    scanf("%d",&ele);
    for(int i=n;i>=ind;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[ind]=ele;
}
void delete(int *arr,int n)
{
    int ind;
    printf("Enter the index of element you want to delete");
    scanf("%d",&ind);
    for(int i=ind;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
}
void search(int *arr,int n)
{
    int key,i,flag=0;
    printf("Enter the element you want to search");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("%d is found at %d index",key,i);
    }
    else
     printf("Element not found");
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
int main()
{
    int n,arr[50];
    char op;
    printf("Enter the length of array");
    scanf("%d",&n);
    printf("Enter the elements of the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    fflush(stdin);
    printf("Enter 'i' to insert 'd' to delete 'f' to find");
    scanf("%c",&op);
    if(op=='i')
    {
        insertion(arr,n);
        n++;
        display(arr,n);
    }
    else if(op=='d')
    {
        delete(arr,n);
        n--;
        display(arr,n);
    }
    else if(op=='f')
    {
        search(arr,n);
    }
    return 0;
}