#include <bits/stdc++.h>
using namespace std;
class TreeNode{
   public:
      int val;
      TreeNode *left, *right;
      TreeNode(int data){
         val = data;
         left = right = NULL;
      }
};
void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         if(val != NULL)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      }
      else{
         q.push(temp->left);
      }
      if(!temp->right){
         if(val != NULL)
            temp->right = new TreeNode(val);
         else
            temp->right = new TreeNode(0);
         return;
      } else {
         q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int> v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}
const int INF = -1e8;
class Solution {
   public:
   void printData(pair <int,int> t){
      cout << t.first << " " << t.second << endl;
   }
   pair <int,int> solve(TreeNode* node){
      if(!node){
         return {INF,0};
      }
      pair <int,int> leftVal = solve(node->left);
      pair <int,int> rightVal = solve(node->right);
      leftVal.first = max(leftVal.first,0);
      leftVal.second = max(leftVal.second,0);
      rightVal.second = max(rightVal.second,0);
      rightVal.first = max(rightVal.first,0);
      int currentVal = max(node->val,0);
      int cantBeAdded = currentVal + leftVal.second + rightVal.second;
      int canBeAdded =max(leftVal.first + rightVal.first,max({
         leftVal.second,rightVal.second,leftVal.second
         + rightVal.second,leftVal.second+rightVal.first,rightVal.second+leftVal.first
      }));
      return {cantBeAdded,canBeAdded};
   }
   int rob(TreeNode* root) {
      pair <int,int> a = solve(root);
      return max(a.first,a.second);
   }
};
main(){
   Solution ob;
   vector<int> v = {3,2,3,NULL,3,NULL,1};
   TreeNode *root = make_tree(v);
   cout << (ob.rob(root));
}
