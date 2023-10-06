//  Breadth First Search
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> list;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum = 0.0;
            for(int i = 0; i < n;  i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            list.push_back(sum/n);
        }
        return list;
    }
};
