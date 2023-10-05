#include <stdio.h>

int main() {
    int B;
    printf("Enter the rows for the Pattern : ");
    scanf("%d", &B);
    for (int P = 1; P <= B; P++) {
        for(int M=1;M<=B-P;M++){
            printf(" ");
        }
        for(int N=1;N<=(2*P)-1;N++){
            printf("*");
        }
        printf("\n");
    }
    for (int P = B; P >= 1;P--){
        for(int M=1;M<=B-P;M++){
            printf(" ");
        }
        for(int N=1;N<=(2*P)-1;N++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}