/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define lca lowestCommonAncestor
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
        return root;//whenever we find p,q ,we return p or q from that node, if not then null from leaf node

        //at any internal node, if both l and r subtree null, return null
        //if one of them not null return that, cuz that one ensures one of the target present there
        //at lca,both left and right will return not null, then return that lca node from there
        //like in the e.g. 5 returns 5 and 1 returns 1 ,at 3 both not null, return 3 which is lca.

        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left==NULL)
        return right;
        else if(right==NULL)
        return left;
        else //both not null,lca found
        return root;
    }
};