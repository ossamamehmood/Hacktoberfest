#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int> &n)
{
    sort(n.begin(), n.end());
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == n[i + 1])
        {
            return true;
        }
    }
    return false;
}
int main()
{

    return 0;
}