#include<iostream>
#include <bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
private:
    void solve(TreeNode* root,vector<string> &ans,string res){
        if(!root) return;
        
        if(root->left || root->right){
            res+=to_string(root->val)+"->";
    
        }
        else{
            res+=to_string(root->val);
            ans.push_back(res);
        }
        
        solve(root->left,ans,res);
        solve(root->right,ans,res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string res;
        solve(root,ans,res);
        
        return ans;
        
    }
};