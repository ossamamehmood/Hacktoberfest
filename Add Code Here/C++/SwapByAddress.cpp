//call by address
#include<iostream>
using namespace std; 
int swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    
}
int main(){
    int x, y;
    cout<<"enter 2 no:";
    cin>>x>>y;
    int z=swap( &x,&y);
    cout<<"after swapping: "<<x<<" "<<y<<endl;
    return 0;
}