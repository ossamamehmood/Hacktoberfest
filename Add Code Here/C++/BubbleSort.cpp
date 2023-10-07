
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 5;
    int arr[5] = {5, 3, 8, 6, 1};

    for (size_t i = 0; i < num; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
    int swap = 0;

    for (size_t i = 0; i < num - 1; i++)
    {
        cout << "pass i: " << i << endl;

        for (size_t j = 0; j < num - i - 1; j++)
        {
            cout << "j: " << j << endl;

            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (size_t i = 0; i < num; i++)
    {
        cout << " " << arr[i];
    }
}
