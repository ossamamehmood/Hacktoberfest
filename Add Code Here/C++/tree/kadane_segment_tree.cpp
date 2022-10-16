//Kadane's Algorithm using segment tree with queries and updates

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

struct Node{
    ll sum, max, pref, suf;
};

int a[N];
Node tree[4*N];

void merge(Node &par, const Node &left, const Node &right){
    par.sum = left.sum + right.sum;
    par.pref = max(left.pref, left.sum + right.pref);
    par.suf = max(right.suf, right.sum + left.suf);
    par.max = max(max(left.max, right.max), left.suf + right.pref);
}

void build(int p, int l, int r){
    if(l == r){
        tree[p].suf = tree[p].pref = tree[p].max = tree[p].sum = a[l];
    }
    else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        build(lc, l, m);
        build(rc, m+1, r);
        merge(tree[p], tree[lc], tree[rc]);
    }
}

void update(int p, int l, int r, int i, int x){
    if(l == r){
        a[i] = tree[p].suf = tree[p].pref = tree[p].max = tree[p].sum = x;
    }
    else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        if(i <= m) update(lc, l, m, i, x);
        else update(rc, m+1, r, i, x);
        merge(tree[p], tree[lc], tree[rc]);
    }
}

Node query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return tree[p];
    else{
        int m = (l+r)/2, lc = 2*p, rc = lc + 1;
        if(qr <= m) return query(lc, l, m, ql, qr);
        else if(ql > m) return query(rc, m+1, r, ql, qr);
        else{
            Node ans;
            merge(ans, query(lc, l, m, ql, qr), query(rc, m+1, r, ql, qr));
            return ans;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1 ; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    int q;
    cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 0){
            int i, x; 
            cin >> i >> x;
            update(1, 1, n, i, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r).max << '\n';
        }
    }

    return 0;
}
