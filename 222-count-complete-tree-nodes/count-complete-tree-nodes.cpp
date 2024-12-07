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
    int getHeight(TreeNode* root, bool left) {
        int height = 0;
        while (root) {
            height++;
            root = left ? root->left : root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);

        if (leftHeight == rightHeight) {
            // Perfect binary tree formula
            return (1 << leftHeight) - 1; // 2^height - 1
        } else {
            // Recursively count left and right subtrees
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
