//https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b3771(link for the problem)
#include <iostream>
using namespace std;
#define ll long long int
int main()
{  #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ll tc;
    cin >> tc;
    ll gg = 1;
    while (gg <= tc)
    {
        cout << "Case #" << gg << ": ";
        gg++;
        ll n, d, c, m;
        cin >> n >> d >> c >> m;//taking input
        string s;
        cin >> s;
        ll dog = 0;
        ll cat = 0;
        ll lid = 0;
        ll lic = 0;
        for (ll i = 0; i < n; i++)//count number of dogs and cats
        {
            if (s[i] == 'D')
            {
                lid = i;
                lic = cat;
                dog++;
            }
            else
                cat++;
        }
        //lic=n-(lid+1);
        if (dog == 0)//check edge cases
        {
            cout << "YES\n";
            continue;
        }
        if (dog > d)
        {
            cout << "NO\n";
            continue;
        }
        if (cat > c)// if at any point dogs are left and cat food is finished then ans is no
        {
            int flag = 1;
            for (ll i = 0; i < lid; i++)
            {
                if (s[i] == 'D')
                {
                    c += m;
                    continue;
                }
                if (s[i] == 'C')
                {
                    if (c > 0)
                    {
                        c -= 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}
