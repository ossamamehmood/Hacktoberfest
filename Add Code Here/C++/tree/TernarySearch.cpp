// C++ program to illustrate
// iterative approach to ternary search

#include <iostream>
using namespace std;

// Function to perform Ternary Search
int ternarySearch(int l, int r, int key, int ar[])

{
    while (r >= l) {

        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }

        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region

        if (key < ar[mid1]) {

            // The key lies in between l and mid1
            r = mid1 - 1;
        }
        else if (key > ar[mid2]) {

            // The key lies in between mid2 and r
            l = mid2 + 1;
        }
        else {

            // The key lies in between mid1 and mid2
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    // Key not found
    return -1;
}

// Driver code
int main()
{
    int l, r, p, key;

    // Get the array
    // Sort the array if not sorted
  int n;
  cin>>n;//array size
  
    int *ar = new int[n];
  for(int i=0;i<n;i++)cin>>ar[i];

    // Starting index
    l = 0;

    // length of array
    r = n;

    // Checking for key

    // Key to be searched in the array
    cin>>key;

    // Search the key using ternarySearch
    p = ternarySearch(l, r, key, ar);

    // Print the result
    cout << "Index of "<<key<<" is " << p << endl;

}
