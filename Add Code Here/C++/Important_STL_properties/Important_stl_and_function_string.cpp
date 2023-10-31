#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "Hello World";
    cout << s << endl;

    // 1. sort
    sort(s.begin(), s.end()); // sort(starting address, ending address)
    cout << s << endl;

    // 2. reverse
    reverse(s.begin(), s.end()); // reverse(starting address, ending address)
    cout << s << endl;

    // 3. min_element
    cout << *min_element(s.begin(), s.end()) << endl; // min_element(starting address, ending address)

    // 4. max_element
    cout << *max_element(s.begin(), s.end()) << endl; // max_element(starting address, ending address)

    // 5. accumulate
    cout << accumulate(s.begin(), s.end(), 0) << endl; // accumulate(starting address, ending address, initial value)//info: accumulate() is used to find the sum of elements in a container.

    // 6. count
    cout << count(s.begin(), s.end(), 'l') << endl; // count(starting address, ending address, element to be counted) //info: count() is used to count the number of occurrences of an element in a container.

    // 7. find
    cout << *find(s.begin(), s.end(), 'l') << endl; // find(starting address, ending address, element to be found)//info: find() is used to find the first occurrence of an element in a container.

    // 8. binary_search
    cout << binary_search(s.begin(), s.end(), 'l') << endl; // binary_search(starting address, ending address, element to be found)

    // 9. lower_bound
    cout << *lower_bound(s.begin(), s.end(), 'l') << endl; // lower_bound(starting address, ending address, element to be found)//info: lower_bound() is used to find the position of the first element in a container which is not less than a specified value.

    // 10. upper_bound
    cout << *upper_bound(s.begin(), s.end(), 'l') << endl; // upper_bound(starting address, ending address, element to be found)

    // 11. rotate
    rotate(s.begin(), s.begin() + 3, s.end()); // rotate(starting address, new starting address, ending address)
    cout << s << endl;

    // 12. next_permutation
    next_permutation(s.begin(), s.end()); // next_permutation(starting address, ending address)
    cout << s << endl;

    // 13. substr
    cout << s.substr(3, 4) << endl; // substr(starting index, length)

    // 14. find_first_of
    cout << s.find_first_of("l") << endl; // find_first_of(string to be found)

    // 15. find_last_of
    cout << s.find_last_of("l") << endl; // find_last_of(string to be found)

    // 16. find_first_not_of
    cout << s.find_first_not_of("l") << endl; // find_first_not_of(string to be found)

    // 17. find_last_not_of
    cout << s.find_last_not_of("l") << endl; // find_last_not_of(string to be found)

    // 18. stoi
    string s1 = "123";
    cout << stoi(s1) << endl; // stoi(string to be converted)

    // 19. to_string
    int x = 123;
    cout << to_string(x) << endl; // to_string(int to be converted)

    // 20. isdigit
    cout << isdigit(s[0]) << endl; // isdigit(character to be checked)

    // 21. isalpha
    cout << isalpha(s[0]) << endl; // isalpha(character to be checked)

    // 22. isalnum
    cout << isalnum(s[0]) << endl; // isalnum(character to be checked)

    // 23. islower
    cout << islower(s[0]) << endl; // islower(character to be checked)

    // 24. isupper
    cout << isupper(s[0]) << endl; // isupper(character to be checked)

    // 25. isxdigit
    cout << isxdigit(s[0]) << endl; // isxdigit(character to be checked)

    // 26. isgraph
    cout << isgraph(s[0]) << endl; // isgraph(character to be checked)

    // 27. isprint
    cout << isprint(s[0]) << endl; // isprint(character to be checked)

    // 28. iscntrl
    cout << iscntrl(s[0]) << endl; // iscntrl(character to be checked)

    // 29. isspace
    cout << isspace(s[0]) << endl; // isspace(character to be checked)

    // 30. isblank
    cout << isblank(s[0]) << endl; // isblank(character to be checked)

    // 31. ispunct
    cout << ispunct(s[0]) << endl; // ispunct(character to be checked)

    // 32. toupper
    cout << toupper(s[0]) << endl; // toupper(character to be converted)

    // 33. tolower
    cout << tolower(s[0]) << endl; // tolower(character to be converted)

    // 34. getline
    getline(cin, s); // getline(input stream, string)

    // 35. stringstream
    stringstream ss;
    ss << s; // ss << string
    ss >> s; // ss >> string

    // 36. stringstream
    stringstream ss1(s); // ss(string)

    // 37. stringstream
    stringstream ss2(s, ios_base::in | ios_base::out); // ss(string, mode)

    // 38. stringstream
    stringstream ss3(s, ios_base::in); // ss(string, mode)

    // 39. stringstream
    stringstream ss4(s, ios_base::out); // ss(string, mode)

    // 40. stringstream
    stringstream ss5(ios_base::in | ios_base::out); // ss(mode)

    // 41. stringstream
    stringstream ss6(ios_base::in); // ss(mode)

    // 42. stringstream
    stringstream ss7(ios_base::out); // ss(mode)

    // 43. stringstream
    stringstream ss8; // ss

    // 44. stringstream
    stringstream ss9(ios_base::app); // ss(mode)

    // 45. stringstream
    stringstream ss10(ios_base::ate); // ss(mode)

    // 46. stringstream
    stringstream ss11(ios_base::binary); // ss(mode)

    // 47. stringstream
    stringstream ss12(ios_base::trunc); // ss(mode)

    // 48. stringstream
    stringstream ss13(ios_base::in | ios_base::out | ios_base::binary); // ss(mode)

    // 49. stringstream
    stringstream ss14(ios_base::in | ios_base::out | ios_base::ate); // ss(mode)

    // 50. stringstream
    stringstream ss15(ios_base::in | ios_base::out | ios_base::app); // ss(mode)

    // 51. stringstream
    stringstream ss16(ios_base::in | ios_base::out | ios_base::trunc); // ss(mode)

    // 52. stringstream
    stringstream ss17(ios_base::in | ios_base::out | ios_base::binary | ios_base::ate); // ss(mode)

    // 53. stringstream
    stringstream ss18(ios_base::in | ios_base::out | ios_base::binary | ios_base::app); // ss(mode)

    // 54. stringstream
    stringstream ss19(ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc); // ss(mode)

    // 55. stringstream
    stringstream ss20(ios_base::in | ios_base::out | ios_base::binary | ios_base::ate | ios_base::app); // ss(mode)

    // 56. stringstream
    stringstream ss21(ios_base::in | ios_base::out | ios_base::binary | ios_base::ate | ios_base::trunc); // ss(mode)

    // 57. stringstream
    stringstream ss22(ios_base::in | ios_base::out | ios_base::binary | ios_base::app | ios_base::trunc); // ss(mode)

    // 58. stringstream
    stringstream ss23(ios_base::in | ios_base::out | ios_base::binary | ios_base::ate | ios_base::app | ios_base::trunc); // ss(mode)

    // 59.
    return 0;
}