#include <iostream>
using namespace std;

void help(int s, int e)
{
    cout << s << " " << e << "\n";
}
int cnt = 0;
void hanoi(int n, int s, int e)
{
    if (n == 1)
    {
        help(s, e);
        // cnt++;
        return;
    }
    int oth = 6 - (s + e);
    hanoi(n - 1, s, oth);
    help(s, e);
    // cnt++;
    hanoi(n - 1, oth, e);
}

void Thanoi(int n, int s, int e)
{
    if (n == 1)
    {
        // help(s, e);
        cnt++;
        return;
    }
    int oth = 6 - (s + e);
    Thanoi(n - 1, s, oth);
    // help(s, e);
    cnt++;
    Thanoi(n - 1, oth, e);
}

int main()
{
    int n;
    cin >> n;
    Thanoi(n, 1, 3);
    cout << cnt << "\n";
    hanoi(n, 1, 3);
}