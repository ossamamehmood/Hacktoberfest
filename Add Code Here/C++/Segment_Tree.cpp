/*

Segment Tree 

A Segment Tree is a data structure that stores information about array intervals as a tree. 
This allows answering range queries over an array efficiently, while still being flexible enough 
to allow quick modification of the array. This includes finding the sum of consecutive array elements 
or finding the minimum element in a such a range in logarithmic time.


Time Complexity :                       n - Size of the array

Tree Construction: O( n )
Query in Range: O( log(n) )
Updating an element: O( log (n) )

Space Complexity : O(n)

Practice Problem Link : https://cses.fi/problemset/task/1648/

*/


#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int n;
    vector<int> t;

    SegmentTree(int n, vector<int> a){
        this->n = n;
        t.resize(2 * n);

        for (int i = n; i < 2 * n; i++)
        {
            t[i] = a[i - n];
        }
    }

    void build(){
        for (int i = n - 1; i > 0; --i)
            t[i] = t[2 * i] + t[2 * i + 1];
    }

    void modify(int p, int value){
        for (t[p += n] = value; p > 1; p /= 2)
            t[p / 2] = t[p] + t[p ^ 1];
    }

    int query(int l, int r){
        r++;
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }
};

int32_t main(){

    int n;
    cin >> n;
    vector<int> v(n) ;

    for(int i=0; i<n; i++) cin >> v[i];
 
    struct SegmentTree S(n,v);
    S.build();
    /*

    Here you can use modify operation on array v by : S.modify(index, new value)
    Also you can use query operation on array v by : S.query( starting index, endng index ); 
    Note that indexing is zero-based.

    Example :
    S.modify(2,5);
    cout << S.query(0,3);

    */
    return 0;
}
