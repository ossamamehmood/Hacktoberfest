//works best when data is uniformly distributed across the range( O(n) )
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketSort(int a[],int n,int k){
    int mx=a[0];
    for(int i=0;i<n;i++)
        mx=max(mx,a[i]);
    mx++;
    vector<int>bkt[k];
    for(int i=0;i<n;i++){
        int bi=(k*a[i])/mx;
        bkt[bi].push_back(a[i]);
    }
    for(int i=0;i<k;i++)
        sort(bkt[i].begin(),bkt[i].end());
    int index=0;
    for(int i=0;i<k;i++)
        for(int j=0;j<bkt[i].size();j++)
            a[index++]=bkt[i][j];
            
}
int main() {
    int a[]={30,40,10,80,5,12,70};
    int n=sizeof(a)/sizeof(int);
    int k=4;
    bucketSort(a,n,k);
    for(int i:a)
        cout<<i<<" ";
}
