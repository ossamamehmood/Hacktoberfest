#include<iostream>
int main(){
    int x,i=0;
    std::cin>>x;
    int arr[x];
    for(int i=0;i<x;++i){
        std::cin>>arr[i];
    }
    int key;
    std::cin>>key;
    int last=arr[x-1];
    arr[x-1]=key;
    while(arr[i]!=key){
        i++;
    }
    arr[x-1]=last;
    if(i<x-1||arr[x-1]==key){
        std::cout<<"Key is Present at Index:"<<i+1;
    }
    else{
        std::cout<<"Key is Not Present";
    }
}
