#include<stdio.h>
int oddeven(int num){
        if(num%2==0){
                return 0;
        }
        else{
                return 1;
        }
}
void main(){
        int number;
        printf("Enter Number Which You Want To Check : ");
        scanf("%d",&number);

        int check = oddeven(number);

        if(check==0){
                printf("The Given Number Is Even");
        }
        else{
                printf("The Given Number Is Odd");
        }
}
