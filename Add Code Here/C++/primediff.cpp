#include <iostream>  //standard input output
#include <conio.h>   //console input output
using namespace std; // to not have to write std:: before cout and cin

// to get difference from nearest prime number N
bool isPrime(int N){
    int factor=0;
    for(int j=1;j<=N;j++){
        if(!(N%j)){
            factor+=1;
        }
    }
    if(factor==2){
        return true;
    }
    return false;
}
int NthTerm(int N){
    if(isPrime(N))
        return 0;
        else{
            int ans=10000000;
            for(int i=2;;i++){
                if(isPrime(i)){
                    int diff;
                    diff=abs(N-i);
                    if(diff>ans)
                        break;
                    else
                        ans=diff; 
                }
            }
            return ans;
        }// Code here
}
int main(){
    cout<<NthTerm(10);
    return 0;
}
