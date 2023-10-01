#include<stdio.h>
int oddeven(int num){
        if(num%2==1)
                return 1;
        else
                return 0;
}
int main(){
        int a,res;
        printf("Enter any number you want to check:",&a);
        scanf("%d",&a);
        res=oddeven(a);
        if(res==1)
                printf("the number is add");
        else
                printf("the number is even");

        return 0;
}