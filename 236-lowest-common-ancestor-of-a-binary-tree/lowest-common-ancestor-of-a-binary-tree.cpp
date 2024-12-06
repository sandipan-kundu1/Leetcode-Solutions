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
        // Base case: if root is null, or root matches p or q, return root
        if (root == NULL || root == p || root == q) 
            return root;

        // Recur for left and right subtrees
        TreeNode* leftLCA = lca(root->left, p, q);
        TreeNode* rightLCA = lca(root->right, p, q);

        // If both left and right subtrees return non-null values, root is the LCA
        if (leftLCA != NULL && rightLCA != NULL) 
            return root;

        // Otherwise, return the non-null value
        return leftLCA != NULL ? leftLCA : rightLCA;
    }
};
