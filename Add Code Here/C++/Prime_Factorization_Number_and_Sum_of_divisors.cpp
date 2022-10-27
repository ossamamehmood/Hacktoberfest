//Made By: Vishesh Gupta(Pre-Final Year at IIT BHU)
//Here I had made the pogram to do Prime factorization of a given Number
//Also I had made program to find the Number of Divisors,Sum of Divisors of the Number

#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<ll,ll>> prime_factorization(ll n){
	vector<pair<ll,ll>> prime_factors;
	// prime_factors stores the prime_factors with their associated power
	for(ll i=2;i*i<=n;i++){
		ll k=0;
		while(n%i==0){
			k++;
			n/=i;
		}
		prime_factors.push_back({i,k});
	}
	if(n>1)prime_factors.push_back({n,1});
	return prime_factors;
}
ll binexp(ll a,ll b){
// To Effectively Calculating the power for finding Sum of divisor
    if(b==0)return 1;if(a==0||a==1)  return a;ll ret=binexp(a,b/2);
    if(b%2) return ((ret*ret)*a);else return (ret*ret);}

int main()
{
	ll n;
	cout<<"Enter the Number :";
	cin>>n;

	vector<pair<ll,ll>> v=prime_factorization(n);

	cout<<"\nPrime Factorization of "<<n<<" is :";
	for(ll i=0;i<v.size();i++){
		for(ll j=0;j<v[i].second;j++){
			cout<<v[i].first<<" ";
		}
	}

	cout<<"\nNumber of Prime Factor of "<<n<<" is :"<<v.size();

	ll number_of_divisor=1,sum_of_divisor=1;
	for(ll i=0;i<v.size();i++){

		ll p =binexp(v[i].first,v[i].second+1);

		number_of_divisor*=v[i].second+1;
		sum_of_divisor*=((p-1)/(v[i].first-1));
	}	

	cout<<"\nNumber of Divisors of "<<n<<" is :"<<number_of_divisor;
	cout<<"\nSum of Divisors of "<<n<<" is :"<<sum_of_divisor;

	return 0;
} 
