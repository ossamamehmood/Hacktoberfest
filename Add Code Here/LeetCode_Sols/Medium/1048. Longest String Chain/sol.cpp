#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static const int LONGEST_WORD_LEN = 16;

    int longestStrChain(vector<string> &words)
    {

        // Count number of words of each length
        vector<int> lenCounts(LONGEST_WORD_LEN + 1, 0);
        int longestCount = 0;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            longestCount = max(longestCount, ++lenCounts[words[i].size()]);
        }

        // Store indexes of words by length
        vector<vector<short>> wcs(LONGEST_WORD_LEN + 1, vector<short>(longestCount + 1, 0));
        int maxWordLen = 0;
        for (maxWordLen = LONGEST_WORD_LEN; maxWordLen > 0 && lenCounts[maxWordLen] == 0; maxWordLen--)
            ;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            int len = words[i].size();
            wcs[len][++wcs[len][0]] = i;
        }

        // Memoization array
        vector<vector<char>> memo(maxWordLen + 1, vector<char>(longestCount + 1, 0));

        // Find longest chain starting from longest words
        int longestFound = 1;
        for (int len = maxWordLen; len > 1 && len >= longestFound; len--)
        {
            for (int i = wcs[len][0]; i >= 1 && len >= longestFound; i--)
            {
                longestFound = max(longestFound, findPath(len, i, wcs, memo, words));
            }
        }

        return longestFound;
    }

private:
    int findPath(int len, int wordIdx, vector<vector<short>> &wcs, vector<vector<char>> &memo, vector<string> &words)
    {
        if (len == 1)
            return 1;
        if (memo[len][wordIdx] > 0)
            return memo[len][wordIdx];

        string curWord = words[wcs[len][wordIdx]];
        int longest = 0;

        for (int i = wcs[len - 1][0]; i >= 1 && longest + 1 < len; i--)
        {
            if (isPredecessor(curWord, words[wcs[len - 1][i]]))
            {
                longest = max(longest, findPath(len - 1, i, wcs, memo, words));
            }
        }

        memo[len][wordIdx] = longest + 1;
        return longest + 1;
    }

    bool isPredecessor(string &cur, string &pred)
    {
        int diffCount = -1;
        int j = pred.size() - 1;

        for (int i = cur.size() - 1; i >= 1; i--)
        {
            if (cur[i] != pred[j--])
            {
                if (++diffCount > 0)
                    return false;
                j++;
            }
        }

        return (j == -1 || cur[0] == pred[0]);
    }
};

int main()
{
    // call the fn here
    return 0;
}