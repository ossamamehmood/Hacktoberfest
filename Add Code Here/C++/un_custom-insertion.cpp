#include<iostream>

using namespace std;




int insertion(int arr[], int size, int capacity, int position, int key){

    if (size >= capacity){
        return size;
    }

    for (int i = size; i >= position; i--){
        arr[i + 1] = arr[i];

    }

    arr[position] = key;

    return (size + 1);

}
int main()
{


    int arr[25] = {1, 2, 3, 4, 5};
    int size = 5; 
    int capacity = sizeof(arr)/sizeof(arr[0]);
    int position, key;



    cout << "Before Insertion ->  ";

    for (int i = 0; i < size; i++){
        cout << arr[i] << " " << flush;

    }


    cout << "Element and Position: ";

    cin >> key >> position;
    position = position -1;
    
    int result = insertion(arr, size, capacity, position, key);

    cout << "After Insertion ->  ";

    for (int i = 0; i < result; i++){
        cout << arr[i] << " " << flush;

    }

    



    return 0;
}
