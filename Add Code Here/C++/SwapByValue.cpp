//swap two numbers by using call by value method
#include<iostream>
using namespace std;
int swap(int a,int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    cout<<"after swapping: "<<a<<" "<<b<<endl;
}
int main(){
    int x, y;
    cout<<"enter 2 no:";
    cin>>x>>y;
    int z=swap(x,y);
    return 0;
}