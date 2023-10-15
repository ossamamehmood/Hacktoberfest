#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(unsigned long long n) {
	vector<bool> isPrime(n + 1, true);
	for(int i = 2; i <= n; i++){
		if(isPrime[i]){
			for(int j = i*i; j <= n; j += i){
				isPrime[j] = false;
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if(isPrime[i])	cout << i << " ";
	}
}

int main() {
	cout << "Enter a number" << endl;
	unsigned long long n;
	cin >> n;
	sieveOfEratosthenes(n);
	return 0;
}