//program for linear search
#include <iostream>
using namespace std;

int linearFunction(int linearArray[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (linearArray[i] == key)
        {
            cout << "The index of that element is " << endl;
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the total elements " << endl;
    cin >> n;

    cout << "Put element in the array " << endl;
    int linearArray[100];
    for (int i = 0; i < n; i++)
    {
        cin >> linearArray[i];
    }

    int key;
    cout << "Enter the key element " << endl;
    cin >> key;
    cout << linearFunction(linearArray, n, key) << endl;
    // linearFunction(linearArray, n, key);
}