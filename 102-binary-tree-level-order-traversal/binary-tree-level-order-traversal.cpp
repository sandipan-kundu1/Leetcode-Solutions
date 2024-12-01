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
    vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {}; // Return an empty vector if the root is null

    queue<TreeNode*> q;
    vector<vector<int>> ans;
    
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        int size = q.size(); // Store the current level size
        for (int i = 0; i < size; i++) {
            TreeNode* t = q.front();
            q.pop();
            
            level.push_back(t->val);
            
            if (t->left != nullptr) 
                q.push(t->left);
            if (t->right != nullptr)  
                q.push(t->right);
        }
        ans.push_back(level);
    }
    return ans;
}

};