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
    bool dfs(TreeNode *l,TreeNode* r)
    {
        if(!l || !r)//if both null true,one null false
        return l==r;
        if(l->val!=r->val)
        return false;
        return dfs(l->left,r->right) && dfs(l->right,r->left);//as mirror image comparing left's left with right's right,left's right with right'sleft
    }
    bool isSymmetric(TreeNode* root) {
        //check traversal (root left right) of left subtree and (root right left) of right subtree
        if(!root)   return true;
        return dfs(root->left,root->right);
    }
};