class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        set<vector<int> >rs;
        sort(num.begin(), num.end());
        int i, j, k;
        int n = num.size();
        for (i = 0; i < n - 2; i++) {
            j = i+1;
            k = n-1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> tmp(3);
                    tmp[0] = num[i];
                    tmp[1] = num[j];
                    tmp[2] = num[k];
                    rs.insert(tmp);
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                }
            }
        }
        vector<vector <int> >result (rs.begin(), rs.end());
        return result;
    }
};
