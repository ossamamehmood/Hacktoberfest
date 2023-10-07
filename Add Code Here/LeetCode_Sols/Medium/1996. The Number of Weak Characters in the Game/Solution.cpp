class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        int count = 0;
        sort(properties.begin(), properties.end(), compare);
        int maxN = INT_MIN;
        for(int i = 0; i < n; i++){
            if(properties[i][1] < maxN)
                count++;
            maxN = max(maxN, properties[i][1]);
        }
        return count;
    }
};
