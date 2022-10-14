#include<bits/stdc++.h>
using namespace std;

int main() {
    int count(0);
    string s = "yd0369";
    cout << "s : " << s << endl;

    // Need to sort first else it will return the permutations from that state itselfY
    sort(s.begin(), s.end());
    cout << "s : " << s << endl;

    do {
        cout << s << ", ";
        count++;
    } while(next_permutation(s.begin(), s.end()));
    cout << "\nTotal Permutations : " << count << endl;
}
