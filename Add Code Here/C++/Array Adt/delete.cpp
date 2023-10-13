#include <iostream>
using namespace std;
struct Array
{
    /* data */
    int A[10];
    int size;
    int length;

};

int Delete(struct Array *arr, int index){
int x=0, i=0;
if(index>=0 && index < arr->length){
    x = arr->A[index];
    for(i = index; i < arr->length-1 ; i++){
        arr->A[i]= arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}
    return 0;
}
int main(){
    struct Array arr1 = {{1,2,3,4,5,6,7,8},10,8};
    cout << Delete(&arr1, 4);
    return 0;
}