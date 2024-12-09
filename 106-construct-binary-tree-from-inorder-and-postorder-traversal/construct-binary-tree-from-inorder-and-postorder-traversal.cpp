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
    TreeNode* build(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int, int>& inmap) {
        // Base case: invalid range
        if (instart > inend || poststart > postend)
            return nullptr;

        // The root is the last element of the current postorder range
        TreeNode* root = new TreeNode(postorder[postend]);

        // Find the root's position in the inorder traversal
        int inroot = inmap[root->val];
        int inleft = inroot - instart;

        // Recursively build left and right subtrees
        root->left = build(inorder, instart, inroot - 1, postorder, poststart, poststart + inleft - 1, inmap);
        root->right = build(inorder, inroot + 1, inend, postorder, poststart + inleft, postend - 1, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // If sizes do not match, return null
        if (inorder.size() != postorder.size())
            return nullptr;

        // Create a hashmap for quick index lookup
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        // Build the tree
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inmap);
    }
};
