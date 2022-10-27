#include <bits/stdc++.h>
using namespace std;

int count_palindromes(string str, int len)
{
    int count = 0, i = 0;
    int arr[len] = {0};
    while (i < len)
    {
        int total = 1;
        int j = i + 1;
        while (str[i] == str[j] && j < len)
        {
            total++;
            j++;
        }
        count += (total * (total * 1) / 2);
        arr[i] = total;
        i = j;
    }
    for (int j = 1; i < len; j++)
    {
        if (str[j] == str[j - 1])
        {
            arr[j] = arr[j - 1];
        }
        int temp = str[j - 1];
        if (j > 0 && j < (len - 1) && (temp == str[j + 1] && str[j] != temp))
        {
            count += min(arr[j - 1], arr[j + 1]);
        }
    }
    count = count - 1;
    return count;
}

int main()
{
    int n;
    cin >> n;
    char s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cout << "count of special palindrom is string is : " << count_palindromes(s, n) << endl;
    return 0;
}