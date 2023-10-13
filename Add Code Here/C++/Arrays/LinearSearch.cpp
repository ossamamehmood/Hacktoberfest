#include <iostream>
using namespace std;
int main(){
    int A[10] = {10,512,8,82,8,55,44,55,45,45}, key;
    cout << "Enter Key: ";
    cin >> key;
    for(int i =0; i< 10 ; i++){

    if (key == A[i]){
        cout << "Found at " << i << endl;
    return 0;
    }
    }
    cout << "Jane de n vro!";
}