#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  for (int j = 0; j < t; j++)
  {
    int n;
    cin >> n;
    vector<pair<string, int>> x;
    vector<pair<int, int>> y;
    for (int i = 0; i < n; i++)
    {
      string c;
      int d, u;
      cin >> c >> d >> u;
      x.push_back({c, u});
      y.push_back({d, u});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      if (x[i].second == y[i].second)
      {
        res++;
      }
    }
    cout << "Case #" << j + 1 << ": " << res << endl;
  }
  return 0;
}