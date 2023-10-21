#include<iostream>
using namespace std;
int main(){
    int row,col;
    cout<<"Enter the values of rows: ";
    cin>>row;
    cout<<"Enter the values of columns: ";
    cin>>col;
    int i = 1;
    int count = 1;
    while (i<=row)
    {
        int j = 1;
        while(j<=i){
            cout<<count<<" ";
            count = count + 1;
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;
    }

    return 0;
    
}