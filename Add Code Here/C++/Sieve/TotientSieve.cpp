
#include<iostream>
#include<vector>
using namespace std;

vector<long long>  phi; // totient function of n

void totient_sieve(long long  n)
{
    // totient function = no. of integers upto n co-prime to n
    phi.clear();
    phi.resize(n + 1);
    for (long long  i = 0; i <= n; i++)
        phi[i] = i;
    for (long long  i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (long long  j = i; i <= n; j += i)
                phi[j] = phi[j] - phi[j] / i;
        }
    }
}

int main(){

    long long  n; cin>> n;
    totient_sieve(n);
    for(auto i : phi) {
        cout<< i  <<" ";
    }
return 0;
}