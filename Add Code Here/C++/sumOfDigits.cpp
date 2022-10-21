#include<bits/stdc++.h>
using namespace std;

int main()
{
  int num;
  
  cin>>num;
  
  int ans=0;
  
  while(num)
  {
    ans+=num%10;
    num/=10;
  }
  
  cout<<ans;
  
  return 0;
}
