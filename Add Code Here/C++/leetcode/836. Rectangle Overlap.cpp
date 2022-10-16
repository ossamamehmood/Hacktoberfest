class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<int>L1;
        L1.push_back(rec1[0]);
        L1.push_back(rec1[1]);
        vector<int>R1;
        R1.push_back(rec1[2]);
        R1.push_back(rec1[3]);
        
        vector<int>L2;
        L2.push_back(rec2[0]);
        L2.push_back(rec2[1]);
        vector<int>R2;
        R2.push_back(rec2[2]);
        R2.push_back(rec2[3]);

        if((L1[0]>=R2[0] || L2[0]>=R1[0]) || (L1[1]>=R2[1] || L2[1]>=R1[1])){
            return false;
        }
        else 
            return true;
    }
};