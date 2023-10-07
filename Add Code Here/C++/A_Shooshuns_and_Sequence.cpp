#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)
#define rep(i, a, n) for (int i=a; i < n; i++)
#define ppb(x) pop_back(x)
#define pb(x) push_back(x)
#define swappy(a,b) a^=b; b^=a; a^=b;
typedef long long ll;
/* Things will definetly not be served to you in a plate, you have to take it forcefully what's yours (Wilson Fisk, Daredevil) */
/* Forgetting is like a wound, the wound may heal but it has already left a scar. (Monkey D. Luffy, the future pirate king) */
/* It's okay to loose your way, just don't loose the sight of what you have decided. (Ronoroa Zoro, the first crew mate of the future pirate king) */
/* Life ins't a single battle, so it's okay to get beat up sometimes (Arthur Leywin's father, TBATE) */
/* There comes a time when a man has to stand and fight! That time is when his friends’ dreams are being laughed at! And I won’t let you laugh at that! ( God Usopp) */
/* Fools who don’t respect the past are likely to repeat it. (Akuma no ko Nico Robin) */
/* There are times when a man has no choice but to act! ( Soul King Brook) */
    
#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> v;
    set<ll> s;
    rep0(i,n)
    {
        ll temp;
        cin>>temp;
        v.pb(temp);
        if(i>=(k-1))
        {
            s.insert(temp);
        }
    }
    for(ll i=k-2;i>=0;i--)
    {
        if(v[i]==v[k-1])
        {
            k=i+1;
        }
        else break;
    }
    // cout<<k<<endl;
    if(s.size()==1)
    {
        cout<<k-1<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }

}
/* -coded by
The Fifth Emperor
Monkey D. Luffy */