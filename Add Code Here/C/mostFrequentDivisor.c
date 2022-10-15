#include <stdio.h>

int main() {
    int x, i, numInicial, count, maior, numMaiorvezes;
    maior = 0;
    scanf("%d", &x);
    
    for(i=2; i<=x; i++) {
        count = 0;
        numInicial = x;
        while(numInicial%i==0) {
            numInicial = numInicial/i;
            count++;
        }
        if(count > maior) {
            maior = count;
            numMaiorvezes = i;
        }
    }
    printf("mostFrequent: %d, ", numMaiorvezes);
    printf("frequency: %d\n", maior);
    return 0;
}