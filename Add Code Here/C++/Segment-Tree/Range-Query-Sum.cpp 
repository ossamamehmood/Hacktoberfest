#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define siz 100009
int arr[siz];
int tree[4*siz];

void maketree(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    maketree(left, b, mid);
    maketree(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int b, int e, int index, int newvalue)
{
    if(b==index && index==e)
    {
        arr[index] = newvalue;
        tree[node] = newvalue;
        return;
    }
    if(b>index || e<index)
    {
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    update(left, b, mid, index, newvalue);
    update(right, mid+1, e, index, newvalue);
    tree[node] = tree[left] + tree[right];
}

ll quary(int node, int b, int e, int qb, int qe)
{
    if(b>qe || e<qb)
    {
        return 0;
    }
    if(qb<=b && qe>=e)
    {
        return tree[node];
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    ll x = quary(left, b, mid, qb, qe);
    ll y = quary(right, mid+1, e, qb, qe);
    return x+y;
}

int main()
{
    int n,i,q;
    cin>>n>>q;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    maketree(1, 1, n);
    while(q--)
    {
        char ch;
        int b,e,index,value;
        cin>>ch;
        if(ch=='s')
        {
            cin>>b>>e;
            ll r= quary(1, 1, n, b, e);
            cout<<r<<endl;
        }
        else
        {
            cin>>index>>value;
            update(1, 1, n, index, value);
        }
    }
}
