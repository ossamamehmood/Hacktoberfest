/*Prabhash Rai*/
/*********************************************************************************************************************************************************************************************************************************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string.h>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define lli long long int
#define lld long double
#define ull unsigned long long
#define nl endl

typedef tree<pair<lli, lli>, null_type, less<pair<lli, lli>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const lli mod= 1e9 +7;
const lli numpr= 1e8 +7;
const lld pi= 3.1415926535897;
vector<lli> adj[10000000];

/*********************************************************************************************************************************************************************************************************************************************************************************************************************************/

void Sieve(vector<lli> &v, lli n){ bool prime[n+1]; memset(prime, true, sizeof(prime)); for (lli p=2; p*p<=n; p++){ if (prime[p] == true){ for (lli i=p*2; i<=n; i += p){ prime[i] = false; }}} for (int p=2; p<=n; p++){ if (prime[p]){ v.push_back(p);}}}
void primefactors(vector<lli> &v, lli n){ vector<lli> prime; Sieve(prime, n); for(auto it: prime){ if(n%it==0){ v.push_back(it); }}}
void factors(vector<lli> &v, lli b) { v.push_back(b); for(int i=2;i*i<=b;i++){if(b%i==0){v.push_back(i); if(i!=b/i){v.push_back(b/i);}}}};
lli gcd(lli a, lli b) {if (b == 0) {return a;} return gcd(b, a % b);}
lli lcm(lli a, lli b) { return (a*(b/gcd(a, b)));}
lli nthfibo(lli n){ double phi= (1 + sqrt(5))/2; return round(pow(phi, n)/2);}
int cntsetbit(lli a){ int ans=0; while(a){ans+= a&1; a>>=1;} return ans;}
int rightmostsetbit(lli n){int temp= n-1; temp= n^n-1; return temp= temp&n;}
int leftmostsetbit(lli n){int k= (int)(log2(n)); return 1<<k;}

/*********************************************************************************************************************************************************************************************************************************************************************************************************************************/


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;

    while(test--){
        lli n, m;
        cin>>n>>m;

        lli a, b, c;

        vector<lli> f(n+1, 0);

        for(int i=0; i<m; i++){
            cin>>a>>b>>c;

            f[b]= 1;
        }

        lli centre= 0;

        for(int i=1; i<=n; i++){
            if(f[i]==0){
                centre= i;
                break;
            }
        }

        for(int i=1; i<=n; i++){
            if(i!= centre){
                cout<<centre<<" "<<i<<nl;
            }
        }
    };

    return 0;
}