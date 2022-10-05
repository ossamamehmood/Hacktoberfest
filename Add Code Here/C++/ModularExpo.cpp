#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;
// Power Calculation
ll modularExpo(int i,int n){
	if(n==0){
		return 1;
	}
	ll m = modularExpo(i,n>>1);
	if(n%2){
		return m*m*i;
	}
	return m*m;
}

int powerSum(int x,int i,int n){
	if(x==0){
		return 1;
	}
	
	ll p = modularExpo(i,n);
	if(p>x){
		return 0;
	}
	// Picking up element
	int a = powerSum(x-p,i+1,n);
	// Not picking
	int b =	powerSum(x,i+1,n);
	return a+b;
}

int main(){
	int x,n;
	cin>>x>>n;
	// int k = sqrt(x);
	cout<<powerSum(x,1,n)<<endl;
	// cout<<modularExpo(x,n)<<endl;
}