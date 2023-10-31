#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v5 = {11, 32, 53, 24, 65};
    // sort
    cout << "sort" << endl;
    sort(v5.begin(), v5.end()); // sort in ascending order
    for (auto i : v5)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;
    sort(v5.begin(), v5.end(), greater<int>()); // sort in descending order
    for (auto i : v5)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // permutation

    vector<int> v = {1, 2, 3, 4, 5};
    cout << "permutation" << endl;
    // prev_permutation
    prev_permutation(v.begin(), v.end()); // 1 2 3 5 4
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // next_permutation
    next_permutation(v.begin(), v.end()); // 1 2 3 5 4
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // rotate
    cout << "rotate" << endl;
    rotate(v.begin(), v.begin() + 2, v.end()); // 3 5 4 1 2
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // reverse
    cout << "reverse" << endl;
    reverse(v.begin(), v.end()); // 2 1 4 5 3
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // accumulate
    cout << "accumulate" << endl;
    int sum = accumulate(v.begin(), v.end(), 0); // 15
    cout << sum << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // count
    cout << "count" << endl;
    int cnt = count(v.begin(), v.end(), 1); // 1
    cout << cnt << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // find
    cout << "find" << endl;
    auto it = find(v.begin(), v.end(), 1); // 1
    cout << *it << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // binary_search
    cout << "binary_search" << endl;
    bool present = binary_search(v.begin(), v.end(), 1); // 1
    cout << present << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // lower_bound
    cout << "lower_bound" << endl;
    auto it = lower_bound(v.begin(), v.end(), 1); // 1
    cout << *it << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // upper_bound
    cout << "upper_bound" << endl;
    auto it = upper_bound(v.begin(), v.end(), 1); // 1
    cout << *it << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // max_element
    cout << "max_element" << endl;
    auto it = max_element(v.begin(), v.end()); // 5
    cout << *it << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // min_element
    cout << "min_element" << endl;
    auto it = min_element(v.begin(), v.end()); // 1
    cout << *it << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // minmax_element
    cout << "minmax_element" << endl;
    auto it = minmax_element(v.begin(), v.end()); // 1 5
    auto it1 = v.begin();
    auto it2 = v.end() - 1;
    cout << *it1 << " " << *it2 << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // is_sorted
    cout << "is_sorted" << endl;
    bool sorted = is_sorted(v.begin(), v.end()); // 0
    cout << sorted << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // is_sorted_until
    cout << "is_sorted_until" << endl;
    auto it = is_sorted_until(v.begin(), v.end()); // 1 2
    cout << *it << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // is_permutation
    cout << "is_permutation" << endl;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5};
    bool permutation = is_permutation(v1.begin(), v1.end(), v2.begin()); // 1
    cout << permutation << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // next_permutation
    cout << "next_permutation" << endl;
    next_permutation(v.begin(), v.end()); // 1 2 3 5 4
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // prev_permutation
    cout << "prev_permutation" << endl;
    prev_permutation(v.begin(), v.end()); // 1 2 3 4 5
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // swap
    cout << "swap" << endl;
    swap(v[0], v[1]); // 2 1 3 4 5
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // swap_ranges
    cout << "swap_ranges" << endl;
    swap_ranges(v.begin(), v.begin() + 2, v.end()); // 3 4 5 1 2
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // transform
    cout << "transform" << endl;
    transform(v.begin(), v.end(), v.begin(), [](int x)
              { return x * x; }); // 9 16 25 1 4
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // fill
    cout << "fill" << endl;
    fill(v.begin(), v.end(), 5); // 5 5 5 5 5
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // remove
    cout << "remove" << endl;
    remove(v.begin(), v.end(), 5); // 5 5 5 5 5
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // remove_if
    cout << "remove_if" << endl;
    remove_if(v.begin(), v.end(), [](int x)
              { return x % 2 == 0; }); // 5 5 5 5 5
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // remove_copy
    cout << "remove_copy" << endl;
    vector<int> v1(5);
    remove_copy(v.begin(), v.end(), v1.begin(), 5); // 5 5 5 5 5
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // remove_copy_if
    cout << "remove_copy_if" << endl;
    vector<int> v1(5);
    remove_copy_if(v.begin(), v.end(), v1.begin(), [](int x)
                   { return x % 2 == 0; }); // 5 5 5 5 5
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // replace
    cout << "replace" << endl;
    replace(v.begin(), v.end(), 5, 1); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // replace_if
    cout << "replace_if" << endl;
    replace_if(
        v.begin(), v.end(), [](int x)
        { return x % 2 == 0; },
        1); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // replace_copy
    cout << "replace_copy" << endl;
    vector<int> v1(5);
    replace_copy(v.begin(), v.end(), v1.begin(), 5, 1); // 1 1 1 1 1
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // replace_copy_if
    cout << "replace_copy_if" << endl;
    vector<int> v1(5);
    replace_copy_if(
        v.begin(), v.end(), v1.begin(), [](int x)
        { return x % 2 == 0; },
        1); // 1 1 1 1 1
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // reverse
    cout << "reverse" << endl;
    reverse(v.begin(), v.end()); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // reverse_copy
    cout << "reverse_copy" << endl;
    vector<int> v1(5);
    reverse_copy(v.begin(), v.end(), v1.begin()); // 1 1 1 1 1
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // rotate_copy
    cout << "rotate_copy" << endl;
    vector<int> v1(5);
    rotate_copy(v.begin(), v.begin() + 2, v.end(), v1.begin()); // 1 1 1 1 1
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // random_shuffle
    cout << "random_shuffle" << endl;
    random_shuffle(v.begin(), v.end()); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // shuffle
    cout << "shuffle" << endl;
    shuffle(v.begin(), v.end(), default_random_engine()); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // unique
    cout << "unique" << endl;
    unique(v.begin(), v.end()); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // unique_copy
    cout << "unique_copy" << endl;
    vector<int> v1(5);
    unique_copy(v.begin(), v.end(), v1.begin()); // 1 1 1 1 1
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // is_partitioned
    cout << "is_partitioned" << endl;
    cout << is_partitioned(v.begin(), v.end(), [](int x)
                           { return x % 2 == 0; })
         << endl; // 1 1 1 1 1
    cout << "----------------------------------------------------------------------" << endl;

    // partition
    cout << "partition" << endl;
    partition(v.begin(), v.end(), [](int x)
              { return x % 2 == 0; }); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // partition_copy
    cout << "partition_copy" << endl;
    vector<int> v1(5), v2(5);
    partition_copy(v.begin(), v.end(), v1.begin(), v2.begin(), [](int x)
                   { return x % 2 == 0; }); // 1 1 1 1 1
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    for (auto i : v2)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // stable_partition
    cout << "stable_partition" << endl;
    stable_partition(v.begin(), v.end(), [](int x)
                     { return x % 2 == 0; }); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // partition_point

    cout << "partition_point" << endl;
    cout << *partition_point(v.begin(), v.end(), [](int x)
                             { return x % 2 == 0; })
         << endl; // 1 1 1 1 1
    cout << "----------------------------------------------------------------------" << endl;

    // stable_sort
    cout << "stable_sort" << endl;
    stable_sort(v.begin(), v.end()); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // partial_sort
    cout << "partial_sort" << endl;
    partial_sort(v.begin(), v.begin() + 2, v.end()); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // nth_element
    cout << "nth_element" << endl;
    nth_element(v.begin(), v.begin() + 2, v.end()); // 1 1 1 1 1
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // is_present
    cout << "is_present" << endl;
    cout << binary_search(v.begin(), v.end(), 3) << endl; // 1 1 1 1 1
    cout << "----------------------------------------------------------------------" << endl;

    return 0;
}