#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int a[N], tree[4*N];

void build(int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
        return;
    }

    int mid = (start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);

    tree[node] = tree[2*node] + tree[2*node+1]; //we generally change this line according to our need
}

int query(int node, int start, int end, int l, int r){
    //no overlapping
    //l........r..start....end
    //st..........end...l.....r
    //no overlapping in both the cases
    if(start > r or end <l) return 0;
    //second case complete overlapping
    //l......start....end....r
    if(l<=start and end<=r) return tree[node];
    //third case: partial overlap
    // st....l....end....r or l....st....r...end
    int mid = (start+end)/2;
    int q1 = query(2*node, start, mid, l, r);
    int q2 = query(2*node+1, mid+1, end, l, r);

    return q1+q2;
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);

    while(1){
        int type; cin>>type;

        if(type==-1) break; // to exit infinite while loop
        if(type==1){
            //For query
            int l, r;
            cin>>l>>r;

            int ans = query(1, 0, n-1, l, r);
            cout<<ans<<endl;
        }
    }
    return 0;
}

/*
INPUT:
8
5 3 2 4 1 8 6 10
1
1 5
OUTPUT:
18
-1 <-- it is input to break the infinite while loop condition
*/