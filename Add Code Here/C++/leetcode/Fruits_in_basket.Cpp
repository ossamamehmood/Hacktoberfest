/** Problem URL:  https://leetcode.com/problems/fruit-into-baskets/  **/
/** Difficulty: Medium **/
/** Concept: Sliding Window **/
class Solution
{
public:
    int totalFruit(vector<int> &s)
    {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<int, int> m;
        while (j < n)
        {
            m[s[j]]++;
            if (m.size() < 2)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (m.size() == 2)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                while (m.size() > 2)
                {
                    m[s[i]]--;
                    if (m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                }
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;
    }
};