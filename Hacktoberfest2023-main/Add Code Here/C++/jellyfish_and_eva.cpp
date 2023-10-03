#include<bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
constexpr int N = 5010;
 
vector<int> adj[N];
 
void sol() {
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n;i ++ ) 
        adj[i].clear();
    vector<int> din(n + 1),dout(n + 1);
    while(m -- ) {
        int a,b;cin >> a >> b;
        adj[b].push_back(a);
        din[b] ++,dout[a] ++;
    }
 
    vector<double> dp(n + 1);
    vector<vector<double> > w(n + 1);
 
    vector<vector<double> > p(n + 1,vector<double>(n + 1));
    p[1][1] = 1,p[2][1] = 0.5;
    for(int i = 3;i <= n;i ++ ) {
        p[i][1] = 1.0 / i;
        for(int j = 2;j <= n;j ++ ) {
            double p1 = 1.0 * (j - 2) / i;
            double p2 = 1.0 * (i - j) / i;
            p[i][j] = p1 * p[i - 2][j - 2] + p2 * p[i - 2][j - 1];
        }
    } 
 
 
    auto topsort = [&]() {
        dp[n] = 1;
        vector<int> deg = dout;
        queue<int> q;
        for(int i = 1;i <= n;i ++ ) 
            if(!dout[i]) q.push(i);
        while(q.size()) {
            int u = q.front(); 
            q.pop();
            sort(w[u].rbegin(),w[u].rend());
            int sz = w[u].size();
            for(int i = 0;i < sz;i ++ )
                dp[u] += p[sz][i + 1] * w[u][i];
 
            for(auto x : adj[u]) {
                w[x].push_back(dp[u]);
                if(-- deg[x] == 0) 
                    q.push(x); 
            }
        }
    };
 
    topsort();
 
    cout << fixed << setprecision(15) << dp[1] << '\n';
}
 
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T;cin >> T;
    while(T -- ) sol();
}
