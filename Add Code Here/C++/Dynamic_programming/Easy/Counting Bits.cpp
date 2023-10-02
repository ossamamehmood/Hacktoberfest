//Link: https://leetcode.com/problems/counting-bits/description/

class Solution {
public:
    int solve(int n, vector <int>& res){
        if(n<2) return n;
        if(res[n] != 0)     return res[n];
        if(n%2 == 0){
            return solve(n/2, res);
        }
        else {
            return 1+solve(n/2, res);
        }
    }
    vector<int> countBits(int n) {
        vector <int> res(n+1, 0);
        for(int i = 0; i<=n; i++){
            res[i] = solve(i, res);
        }
        return res;
    }
};
