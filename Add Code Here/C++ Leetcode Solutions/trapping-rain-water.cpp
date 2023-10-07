// Trapping Rain water Solution in C++
class Solution {
public:
    int trap(vector<int>& height) {
        int maxht=0,n=height.size(),volume=0;
        vector<int> max_to_left(n),max_to_right(n);
        for(int i=0;i<n;i++){
            maxht=max(height[i],maxht);
            max_to_left[i]=maxht;
        }
        maxht=0;
        for(int i=n-1;i>=0;i--){
            maxht=max(height[i],maxht);
            max_to_right[i]=maxht;
        }
        for(int i=0;i<n;i++)
        volume+=min(max_to_left[i],max_to_right[i])-height[i];
        return(volume);
    }
};
