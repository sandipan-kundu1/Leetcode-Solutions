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
    bool valid(TreeNode* root,long long lb,long long ub)
    {
        if(root==NULL)
        return true;
        if(!(lb<root->val && root->val<ub))
        return false;
        return valid(root->left,lb,root->val) && valid(root->right,root->val,ub);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        return true;
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
};