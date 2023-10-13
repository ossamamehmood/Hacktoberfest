#include <iostream>
using namespace std;
struct Array
{
    /* data */
    int A[10];
    int size;
    int length;

};
void swap(int *x, int*y){
    int temp =*x;
    *x =*y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key){
    for(int i =0; i < arr->length; i++){

    if(key == arr->A[i] ){
        swap(&arr->A[i], &arr->A[i-1]);
        return i;
    }
    }
    
    return -1;
}
int main(){
    struct Array arr1 = {{1,2,3,4,5,6,7,8},10,8};
    cout << LinearSearch(&arr1, 5);
    cout << LinearSearch(&arr1, 5);
    cout << LinearSearch(&arr1, 5);
    cout << LinearSearch(&arr1, 5);
    cout << LinearSearch(&arr1, 5);
    cout << LinearSearch(&arr1, 5);
    cout << LinearSearch(&arr1, 5);
    return 0;
}