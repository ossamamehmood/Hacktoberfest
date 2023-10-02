#include <iostream>
using namespace std;

void selectioSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int min = arr[i];
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    
}
int main()
{
    int n;
    cout << "Enter the total value " << endl;
    cin >> n;

    int arr[10];
    cout << "Put the value in an array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectioSort(arr, n);
    cout << "Our sorted array is " << endl;
    printArray(arr, n);

}