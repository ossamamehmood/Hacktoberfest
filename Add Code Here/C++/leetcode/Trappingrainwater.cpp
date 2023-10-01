
#include<bits/stdc++.h>
using namespace std;


int trap(vector < int > & arr) {


    int n=arr.size();
    int prefix[n],suffix[n];

    prefix[0]=arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i]=max(prefix[i-1],arr[i]);
    }

    suffix[n-1]=arr[n-1];
    for (int i = n-2; i >=0 ; i--)
    {
        suffix[i]=max(suffix[i+1],arr[i]);
    }

    int watertrapeed=0;
    for (int i = 0; i < n; i++)
    {
        watertrapeed+=min(prefix[i],suffix[i])-arr[i];
    }
    return watertrapeed;

}



int main(){

  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;



}