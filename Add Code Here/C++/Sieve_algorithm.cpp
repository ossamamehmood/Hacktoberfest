#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef unsigned long int ull;

int main()
{
    int n = 1e5 + 10;
    vector<bool> cp(n, true);
    cp[0] = cp[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (cp[i])
        {
            for (int j = i * 2; j < n; j += i)
            {
                cp[j] = false;
            }
        }
    }

    int num;
    cin >> num;
    
    if (cp[num])
        cout << "prime";
    else if(!cp[num])
        cout << "not prime";
}