#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
    int m, n;
    scanf("%d%d", &m, &n);
    int arr[m][n];
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while(top <= bottom && left <= right){
        for(int i = left ; i <= right ; i++)
            printf("%d ", arr[top][i]);
        top++;
        for(int i = top ; i <= bottom ; i++)
            printf("%d ", arr[i][right]);
        right--;
        for(int i = right ; i >= left ; i--)
            printf("%d ", arr[bottom][i]);
        bottom--;
        for(int i = bottom ; i >= top ; i--)
            printf("%d ", arr[i][left]);
        left++; 
    }
    return 0;
}
