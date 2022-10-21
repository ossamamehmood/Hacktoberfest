#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char len[1000];
    int num=0,flag[10]={0,0,0,0,0,0,0,0,0,0};
    scanf("%s",len);
    num=strlen(len);
    for(int i=0;i<num;i++){
        switch(len[i]){
            case '0':flag[0]=flag[0]+1;
            break;
            case '1':flag[1]=flag[1]+1;
            break;
            case '2':flag[2]=flag[2]+1;
            break;
            case '3':flag[3]=flag[3]+1;
            break;
            case '4':flag[4]=flag[4]+1;
            break;
            case '5':flag[5]=flag[5]+1;
            break;
            case '6':flag[6]=flag[6]+1;
            break;
            case '7':flag[7]=flag[7]+1;
            break;
            case '8':flag[8]=flag[8]+1;
            break;
            case '9':flag[9]=flag[9]+1;
            break;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",flag[i]);
    }
    printf("\n");
    return 0;
}

