class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* root, int remainingSum, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right && remainingSum == root->val) {
            result.push_back(path);
        } else {
            dfs(root->left, remainingSum - root->val, path);
            dfs(root->right, remainingSum - root->val, path);
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};
