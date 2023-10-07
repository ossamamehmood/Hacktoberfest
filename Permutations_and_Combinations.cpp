#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int> &nums, vector<int> &current, vector<bool> &used, vector<vector<int>> &result)
{
    if (current.size() == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
            continue;
        used[i] = true;
        current.push_back(nums[i]);
        generatePermutations(nums, current, used, result);
        current.pop_back();
        used[i] = false;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations;
    vector<bool> used(nums.size(), false);
    vector<int> current;

    generatePermutations(nums, current, used, permutations);

    cout << "Permutations: ";
    for (auto permutation : permutations)
    {
        cout << "[ ";
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
