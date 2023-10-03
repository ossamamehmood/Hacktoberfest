#include<stdio.h>
int oddeven(int num){
        if(num%2==1)
                return 1;
        else
                return 0;
}
int main(){
        int a,res;
        printf("Enter any number to check odd or even :",&a);
        scanf("%d",&a);
        res=oddeven(a);
        if(res==1)
                printf("The number is odd");
        else
                printf("The number is even");

        return 0;
}