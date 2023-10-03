#include<iostream>
using namespace std;

void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
    
}
int main(){
    int firstArr[10] = {0};
    printArray(firstArr, 5);

    cout << "First array done " << endl;

    int secArray[4] = {1,2};
    printArray(secArray, 4);

    cout << "Second array done " << endl;

    int thirdArray[4];
    printArray(thirdArray, 4);


    int forArray[4] = {1,2,3,4,5};
    printArray(forArray, 2);
    cout << "forth array done " << endl;

    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    
}