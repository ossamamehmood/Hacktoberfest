#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int a = (k * l)/nl;
    int b = c * d;
    int z = p / np;
    if(a < b && a < z){
        cout<<(a/n);
    }
    else if(b < a && b < z){
        cout<<(b/n);
    }
    else{
        cout<<(z/n);
    }
    return 0;
}
