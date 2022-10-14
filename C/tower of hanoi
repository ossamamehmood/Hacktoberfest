// you got 3 pillars(a,b,c) , first one fully filled and we need to move a to c , we can get the help of b also.
// rules: 1. only one disk at a time. 2. disk's can only be placed on pillars only

#include <stdio.h>

void TOH (int n, int A, int B, int C){
    if ( n > 0 ){
        TOH (n-1, A, C, B);
        printf("(%d , %d)\n",A,C);
        TOH (n-1, B, A, C);
    }
}

int main(){
    TOH(16, 1, 2, 3);
    return 0;
}
