class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto vec1=nums1.begin();
        auto vec2=nums2.begin();
        vector<int> ans;
        while(vec1!=nums1.end() || vec2!=nums2.end()){
            if(vec1==nums1.end()){
                ans.push_back(*vec2);
                vec2++;        
            }
            else if(vec2==nums2.end()){
                ans.push_back(*vec1);
                vec1++;
            }
            else{
                if(*vec1>*vec2){
                    ans.push_back(*vec2++);
                }
                else{
                    ans.push_back(*vec1++);
                }
            }     
        }
        
        if(ans.size()%2!=0) return ans[ans.size()/2];
        else    return (ans[ans.size()/2-1]+ans[(ans.size()/2)])/2.0;
    }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
