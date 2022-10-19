
#include <bits/stdc++.h>
using namespace std;
 

int findPlatform(int arr[], int dep[], int n)
{
  
  //sort both the arrivial time and departure time array
     sort(arr, arr + n);
    sort(dep, dep + n);
 
    // plat_needed indicates number of platforms and initially it is equal  to 1
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
 
    
    while (i < n && j < n) {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
 
        // Else decrement count of platforms needed
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
 
        
        if (plat_needed > result)
            result = plat_needed;
    }
 
    return result;
}
 
int main()
{
     int arr[] = { 100, 300, 500 };
    int dep[] = { 900, 400, 600 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPlatform(arr, dep, n);
    return 0;
}

//Time Complexity : O(Nlog(N))
// Space Complexity: O(1)
