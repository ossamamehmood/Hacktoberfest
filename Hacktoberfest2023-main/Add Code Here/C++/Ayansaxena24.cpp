#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
     int a,b,c,i,sum1,sum2;
     cin>>a>>b>>c;
     cout<<max(a,max(b,c))<<endl;
  }
}