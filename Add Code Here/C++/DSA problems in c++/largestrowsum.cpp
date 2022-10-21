#include <iostream>
using namespace std;

void printsum(int arr[][3], int row, int col)
{
    for (row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int largestrowsum(int arr[][3], int row, int col)
{
    int maxi = INT32_MIN;
    int rowIndex = -1;
    for (row = 0; row < 3; row++)
    {
        int sum = 0;
        for (col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
    }
    cout << maxi;
    return rowIndex;
}

int main()
{
    // int target;
    int arr[3][3];

    // taking row wise input
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // output
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    printsum(arr, 3, 3);
    cout << endl;
    largestrowsum(arr, 3, 3);
    return 0;
}