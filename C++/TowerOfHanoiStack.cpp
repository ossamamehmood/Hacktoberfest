#include<iostream>
#include<cmath>
#include<stack>
#include<map>
using namespace std ;
void transfer(int n, stack<int> &s, stack<int> &a, stack<int>&d,int g=1,int h=2,int i=3)
{
    if(n==1)
    {
        d.push(s.top());
        s.pop();
        cout << g << " -> " << i << endl;
        return;
    }
    transfer(n - 1,s,d,a,g,i,h);
    d.push(s.top());
    s.pop();
    cout << g << " -> " << i << endl;
    // cout << 3;
    transfer(n - 1, a,s, d,h,g,i);
    // cout << 3;
    return;
}
int main()
{
    stack<int> source;
    stack<int> aux;
    stack<int> dest;
    for (int i = 64; i >= 1; i--)
    {
        source.push(i);
    }
    int n;
    cout << "Enter no. of discs you want transfer from source tower to destinaton tower using auxilliary tower" << endl;
    cin >> n;
    cout << "No. of moves required" << endl;
    int moves = pow(2, n) - 1;
    cout << moves << endl;
    transfer(n, source, aux, dest);
}
