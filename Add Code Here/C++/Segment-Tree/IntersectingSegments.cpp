#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+2, MOD = 1e9+7;

int tree[4*N];

struct triplet{
    int l, r, idx;
};

int query(int node, int start, int end, int l, int r){
    if(start > r or end <l) return 0;
    if(l<=start and end<=r) return tree[node];
    int mid = (start+end)/2;
    int q1 = query(2*node, start, mid, l, r);
    int q2 = query(2*node+1, mid+1, end, l, r);

    return q1+q2;
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        tree[node]=val;
        return;
    }
    int mid = (start+end)/2;
    if(idx<=mid){
        update(2*node, start, mid, idx, val);
    }
    else{
        update(2*node+1, mid+1, end, idx, val);
    }

    tree[node] = tree[2*node] + tree[2*node+1];
}

bool comp(triplet t1, triplet t2){
    return t1.r < t2.r;
}

signed main(){
    int n; cin>>n;
    triplet t1;
    t1.l=t1.r=-1;
    vector<triplet>t(n,t1);
    int x;
    for(int i=0; i<2*n; i++){
        cin>>x;
        if(t[x-1].l==-1) t[x-1].l = i;
        else t[x-1].r = i;
        t[x-1].idx=x;
    }
    sort(t.begin(), t.end(), comp);

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[t[i].idx-1]=(t[i].r - t[i].l -1)-2*query(1, 0, 2*n-1, t[i].l, t[i].r);
        update(1, 0, 2*n-1, t[i].l, 1);
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}

/*
INPUT:
5
5 1 2 2 3 1 3 4 5 4
OUTPUT:
1 0 1 1 1
*/