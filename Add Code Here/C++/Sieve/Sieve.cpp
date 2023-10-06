#include <bits/stdc++.h>
using namespace std;

/*
The sieve of Eratosthenes is used to find all primes smaller than n when n is smaller than 10000000
*/

void Sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

int main() {
    
    int n;
    cin>>n;
    SieveOfEratosthenes(n);
    
}
