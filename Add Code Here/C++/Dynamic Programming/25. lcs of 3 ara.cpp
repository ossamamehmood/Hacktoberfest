#include<bits/stdc++.h>
#define        ll        long long int
#define        ls        unsigned long long
#define         eps       1e-9
#define         M_E      2.718281828
#define         M_PI     3.1416
#define        MAX       500
#define        frin          for(ll i=0;i<n;i++)
#define        frjn          for(ll j=0;j<n;j++)
const int   mod=1e9+7;
using namespace std;
int lcs(vector<ll> &a, vector<ll> &b, vector<ll> &c)
{
    int m=a.size();
    int n=b.size();
    int o=c.size();
	int seq[m+ 1][n + 1][o+ 1];
	for (size_t i = 0; i <= m; i++) {
		for (size_t j = 0; j <= n; j++) {
			for (size_t k = 0; k <= o; k++) {
                    seq[i][j][k] = 0;
            }
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <=o; k++) {
				if (a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1]) {
					seq[i][j][k] = 1 + seq[i - 1][j - 1][k - 1];
				}
				 else {
					seq[i][j][k] =max(seq[i][j][k - 1],max(seq[i][j - 1][k],max(seq[i - 1][j][k],max(seq[i][j - 1][k - 1],max(seq[i - 1][j][k - 1],max(seq[i - 1][j - 1][k],seq[i - 1][j - 1][k - 1]))))));
				}
			}
		}
	}
	return seq[m][n][o];
}

int main()
{
    int m,n,o;
    cin>>m;
    vector<ll>a(m);
     for(int i=0;i<m;i++)cin>>a[i];
     cin>>n;
     vector<ll>b(n);
     for(int i=0;i<n;i++)cin>>b[i];
     cin>>o;
     vector<ll>c(o);
     for(int i=0;i<o;i++)cin>>c[i];
    cout<<lcs(a,b,c)<<endl;
    return 0;
}

