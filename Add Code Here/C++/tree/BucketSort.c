#include <stdio.h>
#include <stdlib.h>

#define tBal 3

typedef struct balde{
    int quant;
    int valor[tBal];
}Balde;

 void insertionSort(int *vet, int tam){
    int i, j, aux;
    for(i = 1 ; i < tam ; i++){
        aux = vet[i];
        for(j = i ; (j > 0) && (aux < vet[j - 1]) ; j--)
            vet[j] = vet[j - 1];
        vet[j] = aux;
    }
 }

void bucketSort(int *vet, int tam){
    int i, j , maior, menor, nBaldes, pos;
    Balde *bd;
    maior = menor = vet[0];

    for(i = 1 ; i < tam ; i++){
        if(vet[i] > maior) maior = vet[i];
        if(vet[i] < menor) menor = vet[i];
    }
    nBaldes = (maior - menor)/ tBal + 1;
    bd = (Balde*)malloc(nBaldes*sizeof(Balde));
    for(i = 0 ; i < nBaldes ; i++)
        bd[i].quant = 0;
    for(i = 0 ; i < tam ; i++){
        pos = (vet[i] - menor)/tBal;
        bd[pos].valor[bd[pos].quant] = vet[i];
        bd[pos].quant++;
    }
    pos = 0;
    for(i = 0 ; i < nBaldes ; i++){
        insertionSort(bd[i].valor, bd[i].quant);
        for(j = 0 ; j < bd[i].quant ; j++){
            vet[pos] = bd[i].valor[j];
            pos++;
        }
    }
    free(bd);
}

int main(){
    int *vet;
    int i, tam;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = (int*)malloc(tam*sizeof(int));

    printf("Preencha o vetor\n");
    for(i = 0 ; i < tam ; i++){
        printf("Elemento %d: ",i+1);
        scanf("%d", &vet[i]);
    }

    printf("Seu vetor desordenado\n");
    for(i = 0 ; i < tam ; i++){
        printf("%d\t", vet[i]);
    }

    bucketSort(vet, tam);

    printf("Seu vetor Ordenado\n");
    for(i = 0 ; i < tam ; i++){
        printf("%d\t", vet[i]);
    }
    return 0;
}
