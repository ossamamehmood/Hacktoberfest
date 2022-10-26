/*
// Structure of the Tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  }
 
  */
 
 bool findPair(TreeNode * root, int k){
 unordered_set<int> values;   // to store the values
 return dfs(root, k, values);
 }
 
 bool dfs(TreeNode* root, int k, unordered_set<int> &values){
     // If complement not found beyond the leaf node, then return false;
     if(root == NULL) return false;
     
     // Find the complement of the current node in the hash table.
     // If found complement, then return true.
     if(values.find(k - root -> val) != values.end()){
             return true;
      }
      
      //Insert the current node value in hashtable.  
      values.insert(root -> val);
      // Same process for node in left and right subtrees.
      return dfs(root -> left, k, values) || 
             dfs(root -> right, k, values);
   }
   
