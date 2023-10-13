#include <iostream>
using namespace std;
class Array{
    int *A;
    int size;
    int length;
public:
    Array(int size){
        this->size = size;
        A = new int [size];
    }

    void Create(){
        cout << "Ente rthe lenght of the Array: "<< flush;
        cin >> length;
        cout << "Enter the elements in the Array: "<< endl;
        for(int i =0; i< length ;i++){
            cout << "Enter the element at index "<< i<< " "<< flush;
            cin>> A[i];
        }
    }
    void Display(){
for(int i = 0; i< length ; i++){
    cout  << "Element at index "<< i << " is "<< A[i] << endl;
}
    }
    ~Array(){
        delete []A;
        cout  << "Array Destroyed!"<< endl;
    }
};
int main(){
    Array Arr(10);
    Arr.Create();
    Arr.Display();
    return 0;
}