#include<bits/stdc++.h>
using namespace std;
#include<vector>

main()
{
    vector<int> arr;

    int n;
    system("cls");
    cout<<"\nEnter size of array: ";
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int inp;
        cin>>inp;
        arr.push_back(inp);
    }
    sort(arr.begin(), arr.end(), greater<int>());

    int k;
    cout<<"\n\nEnter K: ";fflush(stdin);
    cin>>k;

    if(k<n)
        cout<<endl<<arr[k-1]<<"\n\n\n\n\n\n";

    else cout<<"\n\nError"<<"\n\n\n\n\n\n";
}
