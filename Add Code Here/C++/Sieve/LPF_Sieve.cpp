// Calculation Largest Prime Factor using sieve

#include<iostream>
#include<vector>

vector<long long>  lpf; // largest prime factor of n

void lpf_sieve(ll n)
{
    // largest prime factors of numbers upto n
    lpf.clear();
    lpf.assign(n + 1, 0);
    for (ll i = 2; i <= n; i++)
    {
        if (lpf[i] == 0)
        {
            for (ll j = i; j <= n; j += i)
                lpf[j] = i;
        }
    }
}

int main() {
    long long n; cin>> n;

    lpf_sieve(n);

    for(auto i : lpf){
        cout<< i <<" ";
    }
}