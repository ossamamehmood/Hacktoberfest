#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
using namespace std;


 void nextLargerElement(vector<long long> arr, int n){

        stack<ll>s;
vector<ll>vect1;
vector<ll>vect(n,-1);
for(int i=0;i<n;i++){
	while(!s.empty() && arr[s.top()]<arr[i]){	
		vect[s.top()]=(i);	
		s.pop();	
		}s.push(i);
}
for(int i=0;i<n;i++){
	if(vect[i]==-1)
		vect1.push_back(-1);
	else
		vect1.push_back(arr[vect[i]]);

}
for(int i=0;i<vect1.size();i++)
cout<<vect1[i]<<" ";
    }


int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];


  nextLargerElement(arr, n);

    }
	return 0;
}   