#include <bits/stdc++.h>

using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> product;
    vector<int> product2;
    int n = nums.size();
    vector<int> ans(n, 0);
    int p = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        p *= nums[i];
        product.push_back(p);
    }
    int s = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        s *= nums[i];
        product2.push_back(s);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << product[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << product2[i] << " ";
    }
    reverse(product2.begin(), product2.end());
    ans[0] = product2[1];
    ans[n - 1] = product[n - 2];
    for (int i = 1; i < n - 1; i++)
    {
        ans[i] = product[i - 1] * product2[i + 1];
    }

    return ans;
}
int main()
{

    return 0;
}