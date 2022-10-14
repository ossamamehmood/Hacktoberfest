#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int l = 0, mid = 0, h = n-1;
        while(mid<=h){
            if(a[mid]==0)
            {
                swap(a[mid],a[l]);
                l++;
                mid++;
            }
            
            else if(a[mid]==1)
                mid++;
                
            else {
                swap(a[mid], a[h]);
                
                h--;
            }
        }
    }
    
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
