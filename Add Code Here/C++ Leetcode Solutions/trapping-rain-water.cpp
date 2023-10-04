class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int left=0,right=n-1;
        int l=0,r=0,ans=0;
        while(left<=right){
            if(a[left]<=a[right]){
                // left may be contrtibuting
                l=max(l,a[left]);
                ans+=l-a[left];
                left++; 
            }
            else if(a[left]>a[right]){
                r=max(r,a[right]);
                ans+=r-a[right];
                right--;
            }
        }
        return ans;
    }
};