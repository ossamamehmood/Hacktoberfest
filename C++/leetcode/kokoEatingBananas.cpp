class Solution {
public:
    bool canEat(vector<int> v,int k,int h){
        int count=0;
        for(int i=0;i<v.size();i++){
            double val=(double)v[i]/(double)k;
            count+=ceil(val);
            if(count>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //if(n==h)return piles.back();
        int low=1,high=1000000000;
        while(low<high){
            int mid=low+(high-low)/2;
            if(canEat(piles,mid,h)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};
