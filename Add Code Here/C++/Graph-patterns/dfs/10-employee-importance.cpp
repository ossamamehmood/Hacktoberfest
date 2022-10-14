/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
    unordered_map<int, Employee *> mp;

    int dfs(int id)
    {
        auto it = mp[id];
        int ans = it->importance;

        for (auto &s : it->subordinates)
            ans += dfs(s);

        return ans;
    }

public:
    int getImportance(vector<Employee *> emp, int id)
    {
        int n = emp.size();

        for (auto &i : emp)
        {
            mp[i->id] = i;
        }

        return dfs(id);
    }
};