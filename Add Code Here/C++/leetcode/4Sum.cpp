class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>v;
        for(int i=0;i<n-3;) {
            for(int j=i+1;j<n-2;) {
                int sum = k - (arr[i]+arr[j]);
                int l = j+1, r=n-1;
                while(l<r) {
                    if(sum==arr[l]+arr[r])
                    {
                        v.push_back({arr[i],arr[j],arr[l],arr[r]});
                        int t = arr[l], fr = arr[r];
                        while(l<r && arr[l]==t)
                            l++;
                        while(l<r && arr[r]==fr) r--;
                    }
                    else if(sum<arr[l]+arr[r])
                        r--;
                    else l++;
                }
                int s = arr[j];
                while(j<n-2 && arr[j]==s) j++;
            }
            int f = arr[i];
            while(i<n-3 && arr[i]==f) i++;
        }
        return v;
    }
};
