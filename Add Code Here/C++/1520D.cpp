#include <bits/stdc++.h>

using namespace std;

void solve()
{

    int len;

    cin >> len;

    unsigned long long sol = 0;

    vector<int> vec(len);

    unordered_map<int, int> m;

    for (int cntr = 0; cntr < len; cntr++)
    {
        cin >> vec[cntr];

        vec[cntr] = vec[cntr] - cntr;
    }

    for (int cntr = len - 1; cntr >= 0; cntr--)
    {
        if (m.find(vec[cntr]) != m.end())
        {
            sol += m[vec[cntr]];
        }

        m[vec[cntr]]++;
    }

    cout << sol << endl;

    return;
}

int main()
{
    long long tst;

    cin >> tst;

    while (tst--)
    {
        solve();
    }

    return 0;
}