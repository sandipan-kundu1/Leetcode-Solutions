/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL; // Base case
        
        // If root is either p or q, it is the LCA
        if (root->val == p->val || root->val == q->val)
            return root;
        
        // If p and q are on opposite sides of root, root is the LCA
        if ((p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val))
            return root;

        // If both p and q are smaller, LCA is in the left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // If both p and q are greater, LCA is in the right subtree
        return lowestCommonAncestor(root->right, p, q);
    }
};
