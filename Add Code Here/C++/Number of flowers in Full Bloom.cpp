/*
  October 12, 2023 daily problem - https://leetcode.com/problems/number-of-flowers-in-full-bloom/

  Took me 2 soul crushing hours to arrive at the solution. Pure trial and error and pretty inefficient, but the fact that it passes is enough for my soul

  Code - 
  Has a solution class with 2 algorithm methods (one directly what's asked and one helper function) and a testing method. main() calls testing method on solution object.
  
  Algo - 

  1. Create two seperate start and end vectors for flowers, sort each of them.
  2. To deal with duplicates, create sMap and eMap (both unordered_map<int, int>) which store the respectively the last and first index of an element in start and end respectively
  3. Then do binary search of each people[i] in start and end which would find the least greatest for starting indice and greatest least for end indice.
  4. Adjust these indices with sMap and eMap accordingly to get the flower count
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
        vector<int> start, end;
        unordered_map<int, int> sMap, eMap;

        //seperating start and end
        for (auto& f : flowers)
        {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        //eMap contains the first index of every element in end
        eMap[end[0]] = 0;
        for(int i = 1; i < start.size(); i++)
            if(end[i] != end[i-1]) eMap[end[i]] = i;

        //sMap contains the last index of every element in start
        // for this first we reverse it and then store the index
        vector<int> t = start;
        reverse(t.begin(), t.end());
        sMap[t[0]] = t.size() - 1 - 0;
        for(int i = 1; i < start.size(); i++)
            if(t[i] != t[i-1]) sMap[t[i]] = t.size() - 1 - i;

        vector<int> res(people.size(), 0);
        int sIdx, eIdx;

        for(int i = 0; i < people.size(); i++)
        {
            sIdx = idxHelper(start, people[i]);
            if(sIdx < start.size() and start[sIdx] == people[i]) sIdx = sMap[start[sIdx]] + 1;
               
            eIdx = idxHelper(end, people[i]);
            if(eIdx < end.size() and end[eIdx] == people[i]) eIdx = eMap[end[eIdx]];

            res[i] = sIdx - eIdx;
            //cout << people[i] << " " << sIdx << " " << eIdx << endl;
        }
        return res;
    }
    void test_fullBloomFlowers()
    {
        // Test case 1
        vector<vector<int>> flowers1 = { {1, 6}, {3, 7}, {9, 12}, {4, 13} };
        vector<int> people1 = { 2, 3, 7, 11};
        vector<int> expected1 = { 1, 2, 2, 2};
        vector<int> res1 = fullBloomFlowers(flowers1, people1);
        assert(res1 == expected1);

        // Test case 2
        vector<vector<int>> flowers2 = { {1, 10}, {3, 3}};
        vector<int> people2 = {3, 3, 2};
        vector<int> expected2 = {2, 2, 1};
        vector<int> res2 = fullBloomFlowers(flowers2, people2);
        assert(res2 == expected2);

        cout << "All test cases pass" << endl;
    }
private:
    int idxHelper(vector<int>& v, int t)
    {
        int l = 0, r = v.size() - 1, m;

        while(l <= r)
        {
            m = (l+r)/2;

            if(v[m] == t) return m;
            else if(v[m] < t) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};

int main()
{
    Solution s;
    s.test_fullBloomFlowers();
    return 0;
}

