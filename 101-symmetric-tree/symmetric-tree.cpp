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
    bool issym(TreeNode* p,TreeNode* q)
    {
        if(p==NULL || q==NULL)
        return p==q;

        if(p->val!=q->val)
        return false;
        return issym(p->left,q->right) && issym(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;

        return issym(root->left,root->right);
    }
};