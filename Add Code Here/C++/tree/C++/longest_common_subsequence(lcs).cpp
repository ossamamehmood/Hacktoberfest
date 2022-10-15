#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define printa(arr) for(ll i=0,i<n;i++) cout<<arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
                     
/*
    Time Complexity - O(n^2)
    Space Complexity - O(n^2)
*/

ll lcs_top_down(string s1,string s2,ll i,ll j,vector<vector<ll> >&dp){
    //base case
    if(i==s1.size() || j==s2.size()){
        return 0;
    }

    //rec case
    //lookup
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]){
        return dp[i][j]=1+lcs_top_down(s1,s2,i+1,j+1,dp);
    }
    else{
        return dp[i][j]=max(lcs_top_down(s1,s2,i+1,j,dp),lcs_top_down(s1,s2,i,j+1,dp));
    }   
}

ll lcs_bottom_up(string s1,string s2){
    ll n1=s1.size()+1,n2=s2.size()+1;
    vector<vector<ll> > dp(n1,vector<ll>(n2,-1));
    // ll dp[n1][n2];

    //setting all the values of 0th row and 0th column to 0.
    f(i,0,n1){
        dp[i][0]=0;
    }
    f(i,0,n2){
        dp[0][i]=0;
    }

    f(i,1,n2){
        // cout<<"s1[i]: "<<s1[i-1]<<endl;
        f(j,1,n1){
            // cout<<s2[j-1]<<" ";
            if(s1[j-1]==s2[i-1]){
                // cout<<"s1[i]: "<<s1[i-1]<<" s2[j]: "<<s2[j-1]<<endl;
                dp[i][j]=1+dp[i-1][j-1];
                // cout<<"dp[i-1][j-1] "<<dp[i-1][j-1]<<" dp[i][j]: "<<dp[i][j]<<" i: "<<i<<" j: "<<j<<endl;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }    

    // f(i,0,n1){
    //     f(j,0,n2){
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }

    //To print the Longest Common Subsequence
    vector<char> str;
    bool g=true;
    ll i=n1-1,j=n2-1;
    while(g){
        if(dp[i][j]==0){
            g=false;
            break;
        }
        ll mx=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        if(mx==dp[i-1][j-1] && dp[i][j]!=dp[i-1][j-1]){
            str.pb(s2[i-1]);
            i--;j--;
        }
        else{
            if(mx==dp[i-1][j] && mx==dp[i][j-1]){
                if(i-1>=1) i--;
                else j--;
            }
            else if(mx==dp[i-1][j]){
                i--;
            }
            else j--;
        }
    }

    reverse(str.begin(),str.end());
    // cout<<"Longest common subsequence: ";
    // for(auto x:str) cout<<x;
    // cout<<endl;

    return dp[n1-1][n2-1];
}


int main(){
 
    string s1,s2;cin>>s1>>s2;
    ll n1=s1.size(),n2=s2.size();
    vector<vector<ll> > dp(n1,vector<ll>(n2,-1)); 
    // cout<<lcs_top_down(s1,s2,0,0,dp)<<endl;
    cout<<lcs_bottom_up(s1,s2)<<endl;
    // f(i,0,n1){
    //     f(j,0,n2){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}