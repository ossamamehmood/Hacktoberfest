#include <bits/stdc++.h>
using namespace std;
 

void pattern(int value)
{
    
    int row = 2 * value - 1;
    int column = 2 * value - 1;
    int arr[row][column];
 
    int i, j, k;
 
    for (k = 0; k < value; k++) {
 
        
        j = k;
        while (j < column - k) {
            arr[k][j] = value - k;
            j++;
        }
 
      
        i = k + 1;
        while (i < row - k) {
            arr[i][row - 1 - k] = value - k;
            i++;
        }
 
        
        j = column - k - 2;
        while (j >= k) {
            arr[column - k - 1][j] = value - k;
            j--;
        }
 
       
        i = row - k - 2;
        while (i > k) {
            arr[i][k] = value - k;
            i--;
        }
    }
 
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
 

int main()
{
    int n = 5;
    pattern(n);
    return 0;
}
