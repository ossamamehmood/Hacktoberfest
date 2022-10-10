/*
Pattern-->
1 2 3 4 5 6 7 6 5 4 3 2 1 
1 2 3 4 5 6   6 5 4 3 2 1 
1 2 3 4 5       5 4 3 2 1 
1 2 3 4           4 3 2 1 
1 2 3               3 2 1 
1 2                   2 1 
1                       1 
1 2                   2 1 
1 2 3               3 2 1 
1 2 3 4           4 3 2 1 
1 2 3 4 5       5 4 3 2 1 
1 2 3 4 5 6   6 5 4 3 2 1 
1 2 3 4 5 6 7 6 5 4 3 2 1
*/
#include<stdio.h>
void pattern(int);
int sp=2;
int main(){
    pattern(7);
    return 0;
}
// Recursive Function
void pattern(int n){
    if(n==1){
        printf("1                       1\n");
        sp-=4;
        return;
    }
    if(n==7){
        printf("1 2 3 4 5 6 7 6 5 4 3 2 1\n");
        n--;
    }
    for(int i=1; i<=n; i++){
        printf("%d ", i);
    }
    for(int i=1;i<=sp;i++){
        printf(" ");
    }
    sp+=4;
    for(int i=n; i>=1; i--){
        printf("%d ", i);
    }
    printf("\n");
    pattern(n-1);
    for(int i=1; i<=n; i++){
        printf("%d ", i);
    }
    for(int i=1;i<=sp;i++){
        printf(" ");
    }
    sp-=4;
    for(int i=n; i>=1; i--){
        printf("%d ", i);
    }
    if(n==6){
        printf("\n1 2 3 4 5 6 7 6 5 4 3 2 1");
    }
    printf("\n");
}