#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10];
    int i , n , d;
    int flag=0 , temp;
    printf("Enter the no. element in an array: ");
    scanf("%d",&n);

    printf("Enter the array: ");
    for(i = 0; i<n ; i++){
        scanf("%d",&a[i]);
        }
       printf("Enter the element to be deleted: ");
       scanf("%d",&d);
       for(i=0 ; i<n ; i++) {
        if(a[i]==d){
            flag =1;                   //flag is for finding the variable
            temp = i;                 // temp is for location or position
            break;
        }
    }
    if(flag == 1){
        for(i=temp; i< n-1; i++){
            a[i] = a[i+1];
        }
    }
    else{
        printf("The no is not found!!");
}
    printf("The array after deletion of a no. : ");

        for(i=0 ; i<n-1 ; i++){
            printf("%d ", a[i]);
        }

}
