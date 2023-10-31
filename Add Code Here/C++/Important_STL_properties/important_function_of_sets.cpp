#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);

    // 1. sort
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    // 2. reverse
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    // 3. min_element
    cout << *min_element(s.begin(), s.end()) << endl;

    // 4. max_element
    cout << *max_element(s.begin(), s.end()) << endl;

    // 5. accumulate
    cout << accumulate(s.begin(), s.end(), 0) << endl;

    // 6. count
    cout << count(s.begin(), s.end(), 10) << endl;

    // 7. find
    cout << *find(s.begin(), s.end(), 10) << endl;

    // 8. binary_search
    cout << binary_search(s.begin(), s.end(), 10) << endl;

    // 9. lower_bound
    cout << *lower_bound(s.begin(), s.end(), 10) << endl;

    // 10. upper_bound
    cout << *upper_bound(s.begin(), s.end(), 10) << endl;

    // // 11. rotate
    // rotate(s.begin(), next(s.begin()), s.end());

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // cout << endl;

    // // 12. next_permutation
    // next_permutation(s.begin(), s.end());
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // cout << endl;

    // // 13. prev_permutation
    // prev_permutation(s.begin(), s.end());
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    return 0;
}