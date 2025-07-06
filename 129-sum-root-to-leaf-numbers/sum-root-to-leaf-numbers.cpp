class Solution {
public:
    int dfs(TreeNode* root, int currNum) {
        if (!root) return 0;

        currNum = currNum * 10 + root->val;

        // If it's a leaf node
        if (!root->left && !root->right)
            return currNum;

        // Recurse left and right
        return dfs(root->left, currNum) + dfs(root->right, currNum);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
