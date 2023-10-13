#include <iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        cout << "Element at index "<< i << " is "<< arr.A[i]<< endl;
    }
}
void Append(struct Array *arr, int x){
    if(arr->length< arr->size){
        arr->A[arr->length++] = x;
    }
}
void Insert(struct Array *arr,int index, int x){
    if(index >= 0 && index <= arr->length){
        for(int i = arr-> length; i> index;i--){
            arr->A[i] = arr->A[i-1];
            
        }
        arr->A[index] = x;
            arr->length++;
    }
}
int main(){
    struct Array arr{{1,2,3,4,5,6,7,8},10,8};
    Append(&arr, 9);
    Insert(&arr, 5,10);
    Display(arr);
    return 0;
}