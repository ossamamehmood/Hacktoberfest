class Solution {
public:
    TreeNode* createBST(vector<int> nums, int s, int e) {
        if (s > e) return NULL;

        int mid = s + (e - s) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(nums, s, mid - 1);
        root->right = createBST(nums, mid + 1, e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        return createBST(nums, s, e);
    }
};