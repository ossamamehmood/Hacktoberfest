//problem statement:- https://www.codechef.com/problems/AMR15A

#include<iostream>
using namespace std;

string getResult(int arr[],int num){
    int oddCounter=0,evenCounter=0;
    for(int j=0;j<num;++j){
        if(arr[j]%2==0){
            ++evenCounter;
        }
        else{
            ++oddCounter;
        }
    }
    return evenCounter>oddCounter?"READY FOR BATTEL":"NOT READY";
}

int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;++i){
        cin>>arr[i];
    }
    cout<<getResult(arr,num);
    return 0;
}
