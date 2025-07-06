class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf node
        if (!root->left && !root->right)
            return targetSum == root->val;

        int newTarget = targetSum - root->val;

        return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
    }
};
