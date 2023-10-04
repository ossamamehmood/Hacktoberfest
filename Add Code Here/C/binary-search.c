#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
    while (high >= low) {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (array[mid] == x)
            return mid;

        // Search the left half
        if (array[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;  // Search the right half
    }

    return -1;
}

int main(void) {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int array[n];
    
    printf("Enter %d sorted integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    int x;
    printf("Enter the number to search for: ");
    scanf("%d", &x);
    
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        printf("Not found\n");
    else
        printf("Element is found at index %d\n", result);
    return 0;
}

