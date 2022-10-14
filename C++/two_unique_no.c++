#include <iostream>
using namespace std;

int setBit(int n, int pos){
    return((n & (1<<pos))!=0);
}

void unique(int arr[], int n){
    int xorsum = 0;
    for(int i=0;i<n;i++){
        xorsum = xorsum ^ arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while(setbit != 1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i], pos-1)){
            newxor = newxor ^ arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}
int main(int argc, const char * argv[]) {
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unique(arr, n);
    return 0;
}