//Problem Link -: https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>arr;
        vector<vector<int>> res;
        arr.push_back(1);
        res.push_back(arr);
        for(int i=1;i<numRows;i++){
            vector<int>brr;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    brr.push_back(1);
                }else{
                    brr.push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
            res.push_back(brr);
        }
        return res;
    }
};
