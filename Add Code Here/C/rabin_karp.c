#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000

int sp_h = 0;
void rabinKarp(char* pattern, char*text, int d, int q){

    int M = strlen(pattern);
    int N = strlen(text);
    int s, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;


    for (int i = 0; i < M; i++){
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (s = 0; s <= N - M; s++){
        if (p == t){
            for (j = 0; j < M; j++){
                if (text[s + j] != pattern[j]) break;
           }
            if (j == M)
              printf ("Pattern found at index %d\n", s);
            else    sp_h++;
        }
        if (s < N - M){
            t = (d * (t - text[s] * h) + text[s + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }

}

int main(){

    char text[SIZE],pattern[SIZE]; 
    printf("Enter Text : ");
    scanf("%[^\n]%*c", text);

    printf("Enter Pattern : ");
    scanf("%[^\n]%*c", pattern);
    rabinKarp(pattern, text, 10, 11);
    printf("The no. of spurious hits are:");
    printf("%d", sp_h);
}



