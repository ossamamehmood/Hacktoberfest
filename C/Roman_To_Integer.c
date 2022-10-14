//Contributed by: Aaditya1612
//Capable of converting Roman number into integer

#include<stdio.h>
#include<string.h>

int romanToInt(char * s){
    
    int result=0;
    
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='M')
                result+=1000;
        else if(s[i]=='D')
            result+=500;
        else if(s[i]=='C'){
            result+=100;
            if(s[i+1]=='D'|| s[i+1]=='M')
                    result-=200;
        }
        else if(s[i]=='L')
            result+=50;
        else if(s[i]=='X'){
            result+=10;
            if(s[i+1]=='L' || s[i+1]=='C'){
                    result-=20;
                }
        }
        else if(s[i]=='V')
            result+=5;
        else{
            result+=1;
            if(s[i+1]=='V' || s[i+1]=='X')
                    result-=2;
        }
    }
    return result;

}

int main(){
    
    char roman[] =  "XV"; //Sample test case
    printf("%d", romanToInt(roman));
    
}
