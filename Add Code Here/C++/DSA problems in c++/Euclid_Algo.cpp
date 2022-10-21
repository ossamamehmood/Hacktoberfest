#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MAX 1e9+7
#define MIN -1e9-7
#define mem memset(a, 0, sizeof(a))
#define pb push_back

int gcd(int a,int b)
{
  if(b==0)
  {
    return a;
    //when b=0 than a is ans
  }
  //else we are caling gcd function again
  gcd(b,a%b);

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    //the numbers you want to calculate gcd
    cin>>n>>m;
    cout<<gcd(n,m)<<endl;
    //you can also use c++ inbulet function to calculate GCD
    //__gcd(n,m);
    cout<<__gcd(n,m)<<endl;
  
return 0;
}
