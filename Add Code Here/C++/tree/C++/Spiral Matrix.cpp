//question link: https://leetcode.com/problems/spiral-matrix/
//Please consider this under hacktober fest



class Solution {
public:
    vector<int> spiralOrder( vector<vector<int>> A) {
 int T,B,L,R,dir;
 T=0;
 B=A.size()-1;
 L=0;
 R=A[0].size()-1;
 dir=0;
 vector <int> ans;
 int i;
 while(T<=B && L<=R){
     if(dir==0){
         for( i=L; i<=R; i++){
             ans.push_back(A[T][i]);
         }
         T++;
     }
     else if(dir==1){
             for( i=T; i<=B; i++){
                 ans.push_back(A[i][R]);
             }
            R--;
         }
     else if(dir==2){
         for( i=R; i>=L; i--){
             ans.push_back(A[B][i]);
         }
         B--;
     }
     else if (dir==3){
         for( i=B; i>=T; i--){
             ans.push_back(A[i][L]);
         }
         L++;
     }
     dir=(dir+1)%4;
     }
     return ans;
 }
};
