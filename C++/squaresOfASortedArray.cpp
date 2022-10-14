#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& n) {
    sort(n.begin(), n.end(),
         [](int& n1, int& n2) { return abs(n1) < abs(n2); });
    for_each(n.begin(), n.end(), [](int& x) { x *= x; });
    return n;
}

int main() {
    vector<int> v {
        -7, -3, 2, 3, 11
    };

    vector<int> res = sortedSquares(v);
    for(const int x: res) {
        cout << x << " ";
    }
}