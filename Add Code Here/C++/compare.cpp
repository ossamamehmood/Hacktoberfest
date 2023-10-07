#include <bits/stdc++.h>

using namespace std;

int CompaareTriplet(int a, int b) {
    if (a > b) { return a; }
    else if (a < b)
    {
        return b;
    }
    return 0;
}
int main()
{
    int al[3],bob[3];
    int am = 0, bm = 0;
    for (int i = 0; i < 3; i++)
    {
        cin>>al[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin>>bob[i];
    }
    for (int i = 0; i < 3; i++)
    {
        int k = CompaareTriplet(al[i],bob[i]);
        if(k == al[i]){
            am++;
        }else if (k ==bob[i])
        {
            bm++;
        }else{
            am +=k;
            bm += k;
        }
        
    }
    cout<<am<<" "<<bm;
    return 0;
}
