//Name : Akashdeep-k
//Date : 15/10/2022

//Write a program to convert a binary number into an positive integer
//100 --> 4
#include<iostream>
#include<math.h>
using namespace std;
int BinaryToDecimal(int n){
    int ans = 0, i = 0;
    int rem;
    while(n){
        rem = n%10;
        if(rem == 1){
            ans = pow(2, i) + ans;
        }
        i++;
        n = n / 10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int integer = BinaryToDecimal(n);
    cout<<integer;
    return 0;
}