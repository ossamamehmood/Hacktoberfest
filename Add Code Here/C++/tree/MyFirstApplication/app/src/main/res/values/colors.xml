#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n = 6; // array size

  int arr[n] = {1 , 3, 7, 8, 10, 13 };

  int target_sum = 9;

  bool possible = false;

  int i=0; // left pointer
  int j=n-1; // right pointer

  while( i < j && i<=n-1 && j >= 0)
  {
    if( arr[i] + arr[j] > target_sum)
    {
      j--;
    }
    else if( arr[i] + arr[j] < target_sum )
    {
      i++;
    }
    else
    {
      possible = true;
      break;
    }

  }
  


  if(possible)
  {
    cout<<"index1 : "<<i<<" , index2 : "<<j<<endl;

    cout<<"value at index1 : "<<arr[i]<<endl;
    cout<<"value at index2 : "<<arr[j]<<endl;
  }
  else
  {
    cout<<"No two elements sums to the given target\n";
  }
}
