#include <bits/stdc++.h>

#define ll long long int
#define F first
#define S second
#define pb push_back
#define all(p) p.begin(), p.end()
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
////////////////////////////////////////////////////////////////

int getitBit(int n, int i)
{
    i = 1 << (i - 1);
    if (n & i)
        return 1;
    else
        return 0;
}
void setIthBit(int &n, int i)
{
    i = (1 << (i - 1));
    n = n | i;
}
void clearIthBit(int &n, int i)
{
    i = ~(1 << (i - 1));
    n = n & i;
}
void updateIthBit(int &n, int i)
{
    i = (1 << (i - 1));
    n = n & i;
}
void showAllBits(int n)
{
    int x = 8;
    int y = pow(2, 7);
    while (x)
    {
        if (x != 8)
            y = y >> 1;
        if (n & y)
            cout << "1";
        else
            cout << "0";
        x--;
    }
    cout << endl;
}

void clearLastBits(int &n, int i)
{
    showAllBits(n);
    n = n & (-1 << i); // 00001111 & 11111100    -1 -> 1111111111111111111111 <- ~0
    showAllBits(n);
}

void clearBitsInRange(int &n, int i, int j)
{
    int x = -1 << (i); //  let's i=4  11110000
                       /* int y = pow(2, j - 1) - 1; // let's j=2  00000001 */
    int y = (1 << j) - 1;
    showAllBits(n);
    x = x | y;

    n = n & (x);
    showAllBits(n);
}

int main()
{
    int n, i, j;
    cin >> n >> i >> j;
    // clearLastBits(n, i);
    clearBitsInRange(n, i, j);
    // cout << getitBit(n, i);
    return 0;
}