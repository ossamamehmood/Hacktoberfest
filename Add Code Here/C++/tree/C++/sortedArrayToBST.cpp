#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 
TreeNode *bstFromSortedVector(const vector<int> &A,int s, int e){
    if(s>e){
        return (NULL);
    }
    
    int mid = (s+e)/2;
    TreeNode *root = new TreeNode(A[mid]);
    root->left = bstFromSortedVector(A,s,mid-1);
    root->right = bstFromSortedVector(A,mid+1,e);
    
    return (root);
    
    
    
}
TreeNode *sortedArrayToBST(const vector<int> &A) {
    
    TreeNode *root =  bstFromSortedVector(A,0,A.size()-1);
    return (root);
    
}