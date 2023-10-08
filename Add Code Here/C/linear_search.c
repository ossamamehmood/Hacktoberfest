#include <stdio.h>
#include<stdlib.h>
int linear_search(int a[],int b,int c);
int main(){
    int n;
    printf("Enter the length of list : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of list : ");
     for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
            }
    int item;
    printf("enter the element you want to search : ");
    scanf("%d",&item);
    int pos;
    pos=linear_search(arr,n,item);
    if(pos == -1){
        printf("search unsuccesful .;");
    }    
    else{
        printf("the element is on %d location of array",pos);
    }
    return 0;
}
int linear_search(int a[],int b, int c){
    int loc=0;
    for(int i=1;i<=b;i++){
        if(a[i]==c){
            loc=i;
        }
        else {
            loc=-1;
        }
    }
    return loc;
}