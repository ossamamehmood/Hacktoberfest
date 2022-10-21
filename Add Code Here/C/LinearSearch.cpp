
#include <iostream>
using namespace std;
int main()
{
    int size;
    int position, fact = 0, n;
    cout << "Enter number of elements: ";
    cin >> size;
    int a[size];
    cout << "\nEnter Elements of the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    int e;
    cout << "Enter element to search: ";
    cin >> e;
    for (int j = 0; j < size; j++)
    {
        if (a[j] == e)
        {
            fact = 1;
            position = j;
        }
    }
    if (fact == 1)
    {
        cout << "\nElement is found at index " << position << endl;
        cout << "\n";
    }
    else
    {
        cout << "\nElement not found in the array.";
        cout << "\n";
    }
}
