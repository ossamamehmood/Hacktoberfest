#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10] = {11, 23, 53, 64, 75, 16, 27, 88, 69, 10}; // array of size 10

    // 1. sort
    sort(a, a + 10); // sort(starting address, ending address)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 2. reverse
    reverse(a, a + 10); // reverse(starting address, ending address)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 3. min_element
    cout << *min_element(a, a + 10) << endl; // min_element(starting address, ending address)

    // 4. max_element
    cout << *max_element(a, a + 10) << endl; // max_element(starting address, ending address)

    // 5. accumulate
    cout << accumulate(a, a + 10, 0) << endl; // accumulate(starting address, ending address, initial value)

    // 6. count
    cout << count(a, a + 10, 10) << endl; // count(starting address, ending address, element to be counted)

    // 7. find
    cout << *find(a, a + 10, 10) << endl; // find(starting address, ending address, element to be found)

    // 8. binary_search
    cout << binary_search(a, a + 10, 10) << endl; // binary_search(starting address, ending address, element to be found)

    // 9. lower_bound
    cout << *lower_bound(a, a + 10, 10) << endl; // lower_bound(starting address, ending address, element to be found)

    // 10. upper_bound
    cout << *upper_bound(a, a + 10, 10) << endl; // upper_bound(starting address, ending address, element to be found)

    // 11. rotate
    rotate(a, a + 3, a + 10); // rotate(starting address, new starting address, ending address)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 12. next_permutation
    next_permutation(a, a + 10); // next_permutation(starting address, ending address)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 13. prev_permutation
    prev_permutation(a, a + 10); // prev_permutation(starting address, ending address)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 14. swap
    swap(a[0], a[9]); // swap(element 1, element 2)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 15. swap_ranges
    swap_ranges(a, a + 5, a + 5); // swap_ranges(starting address 1, ending address 1, starting address 2)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 16. reverse_copy
    reverse_copy(a, a + 10, a); // reverse_copy(starting address, ending address, starting address)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 17. rotate_copy
    rotate_copy(a, a + 3, a + 10, a); // rotate_copy(starting address, new starting address, ending address, starting address)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 18. is_sorted
    cout << is_sorted(a, a + 10) << endl; // is_sorted(starting address, ending address)

    // 19. is_partitioned
    cout << is_partitioned(a, a + 10, [](int x)
                           { return x % 2 == 0; })
         << endl; // is_partitioned(starting address, ending address, condition)

    // 20. partition
    partition(a, a + 10, [](int x)
              { return x % 2 == 0; }); // partition(starting address, ending address, condition)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 21. stable_partition
    stable_partition(a, a + 10, [](int x)
                     { return x % 2 == 0; }); // stable_partition(starting address, ending address, condition)
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // 22. partition_point
    auto it = partition_point(a, a + 10, [](int x)
                              { return x % 2 == 0; }); // partition_point(starting address, ending address, condition)
    cout << *it << endl;

    // 23. random_shuffle
    random_shuffle(a, a + 10); // random_shuffle(starting address, ending address)

    // 24. shuffle
    shuffle(a, a + 10, default_random_engine()); // shuffle(starting address, ending address, random engine)

    // 25. max
    cout << max(2, 3) << endl; // max(element 1, element 2)

    // 26. min
    cout << min(2, 3) << endl; // min(element 1, element 2)

    // 27. memset
    int b[10];
    memset(b, 0, sizeof(b)); // memset(starting address, value to be filled, size of the array)

    // 28. is_permutation
    cout << is_permutation(a, a + 10, b) << endl; // is_permutation(starting address 1, ending address 1, starting address 2)

    // 29. next
    auto it = std::next(std::begin(a), 1); // get iterator to second element of array a

    // 30. prev
    auto it = std::prev(std::end(a), 1); // get iterator to last element of array a

    // 31. iota
    iota(a, a + 10, 1); // iota(starting address, ending address, value to be filled)

    // 32. gcd
    cout << __gcd(10, 20) << endl; // __gcd(element 1, element 2)//info: __gcd is a inbuilt function for finding gcd of two numbers

    // 33. lcm
    cout << lcm(10, 20) << endl; // lcm(element 1, element 2)

    return 0;
}