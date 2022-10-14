class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int index=0;
        
        sort(n.begin(), n.end());
        for(int i=0;i<n.size()-1;i++){
            if(n[i]==n[i+1]){
                index=n[i];
                break;
            }
        }
        return index;
    }
};


