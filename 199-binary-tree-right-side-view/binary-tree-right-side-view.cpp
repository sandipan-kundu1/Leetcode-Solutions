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
    void rightview(TreeNode* node,vector<int> &ds,int level)
    {
        if(node==NULL)
        return;

        if(level==ds.size())
        ds.push_back(node->val);

        rightview(node->right,ds,level+1);
        rightview(node->left,ds,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        if(root==NULL)
        return ds;

        rightview(root,ds,0);
        return ds;
    }
};