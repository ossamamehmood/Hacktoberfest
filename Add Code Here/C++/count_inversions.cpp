/**
 * Count inversions such that i<j and arr[i]>arr[j]
 * */

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<class T> fin(vector<T> &v){ int n=v.size(); for(int i=0; i<n; i++) cin>>v[i];}
template<class T> fin(vector<vector<T>> &v){ int n=v.size(); int m=v[0].size(); for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>v[i][j];}

void task();

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
  	int t=1;
  	// cin>>t;
	while(t--)
  	task();
	return 0;
}
int merge(vector<int> &arr, vector<int> &temp, int start, int end){
	int cnt=0;
	int mid = start + (end-start)/2;
	int i=start, j=mid+1;
	int k=start;
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}else{
			cnt += mid-i+1;
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid) temp[k++] = arr[i++];
	while(j<=end) temp[k++] = arr[j++];

	for(int i=start; i<=end; i++) arr[i] = temp[i];
	return cnt;
}

int count_inversion(vector<int> &v, vector<int> &temp, int start, int end){
	int cnt=0;
	if(start<end){
		int mid = start + (end-start)/2;
		cnt += count_inversion(v, temp, start, mid);
		cnt += count_inversion(v, temp, mid+1, end);
		cnt += merge(v, temp, start, end);
	}
	return cnt;
}


void task(){
	int n;
	cin>>n;
	vector<int> v(n);
	fin(v);
	vector<int> temp(n);
	int ans = count_inversion(v, temp, 0, n-1);
	cout<<"Number of inversions: "<<ans<<endl;
	debug(v)
}