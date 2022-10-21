//encrypt a string by adding 1 to the ascii value of its characters
#include<stdio.h>
#include<string.h>
void encrypt (char *str){
    char *ptr=str;
    while(*ptr!='\0'){
        *ptr=*ptr+1;
        ptr++;
    }
}
int main(){
    char str[]="mwonusee";
    encrypt(str);
    printf("Encrypted string:%s",str);
    return 0;
}