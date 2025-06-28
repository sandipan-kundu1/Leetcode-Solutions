/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = 0;

    // returns {isBST, minVal, maxVal, sum}
    vector<int> dfs(TreeNode* root) {
        if (!root) return {1, INT_MAX, INT_MIN, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left[0] && right[0] && root->val > left[2] && root->val < right[1]) {
            int sum = root->val + left[3] + right[3];
            maxSum = max(maxSum, sum);
            int minVal = min(root->val, left[1]);
            int maxVal = max(root->val, right[2]);
            return {1, minVal, maxVal, sum};
        }

        return {0, 0, 0, 0}; // not a BST
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};