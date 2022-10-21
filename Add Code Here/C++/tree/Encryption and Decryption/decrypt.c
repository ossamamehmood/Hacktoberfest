// to decrpyt what we just encrypted , we subtract 1 from the ascii value of the encrypted message.
#include<stdio.h>
#include<string.h>
void decrypt (char *str){
    char *ptr=str;
    while(*ptr!='\0'){
        *ptr=*ptr-1;
        ptr++;
    }
}
int main(){
    char str[]="nxpovtff";
    decrypt(str);
    printf("Decrypted string:%s",str);
    return 0;
}
