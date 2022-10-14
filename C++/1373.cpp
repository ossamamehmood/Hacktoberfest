class Solution
{
public:
    int mx = 0;

    pair<bool, vector<int>> func(TreeNode *root)
    {
        if (root == NULL)
        {
            return {true, {0, 0, 0}};
        }

        pair<bool, vector<int>> left = func(root->left);
        pair<bool, vector<int>> right = func(root->right);

        int sum = left.second[0] + right.second[0];
        sum += root->val;

        vector<int> temp(3, 0);

        temp[0] = sum;
        temp[1] = left.second[1];
        temp[2] = right.second[2];

        bool flag = true;

        if (root->left)
        {
            if (root->val <= root->left->val || root->val <= temp[1])
            {
                flag = false;
            }
        }

        if (root->right)
        {
            if (root->val >= root->right->val || root->val >= temp[2])
            {
                flag = false;
            }
        }

        if (root->left && root->right)
        {
            temp[1] = max(max(left.second[1], right.second[1]), root->val);
            temp[2] = min(min(right.second[2], left.second[2]), root->val);
        }
        else if (root->left == NULL && root->right == NULL)
        {
            temp[1] = root->val;
            temp[2] = root->val;
        }
        else if (root->left == NULL)
        {
            temp[1] = right.second[1];
            temp[2] = root->val;
        }
        else
        {
            temp[1] = root->val;
            temp[2] = left.second[2];
        }

        if (flag && left.first && right.first)
        {
            mx = max(mx, sum);
            return {true, temp};
        }

        return {false, temp};
    }

    int maxSumBST(TreeNode *root)
    {
        func(root);
        return mx;
    }
};