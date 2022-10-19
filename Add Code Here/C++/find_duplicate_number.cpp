/*Some integral elements are taken in input, which may occur once or twice ,the repeated 
element is considered as duplicate and this code prints the repeated elements in output
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<< "enter total number of integral elements"<<endl;

    cin>>n;
    int arr[n];
    cout<< "enter the integral elements"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x=arr[i]^arr[j];
            if (x==0)
            {
                cout<< "Repeated Element = "<<arr[i]<<endl;
            }
        }
    }
    return 0;
}

/*Sample Input:
enter total number of integral elements
10
enter the integral elements
1 5 6 4 5 4 1 2 3 2
Sample Output:
Repeated Element = 1
Repeated Element = 5
Repeated Element = 4
Repeated Element = 2
*/

// Time Complexity - O(n^2)
// Space Complexity - O(n^2)
