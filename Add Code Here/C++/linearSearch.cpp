#include <iostream>

using namespace std;

int main(){

    int a[]={1,2,3,4,5};

    int k;

    cin>>k;

    for (int i=0;i<sizeof(a);i++){
        if(k==a[i])
        cout<<"Found";
    }

    return 0;
}
