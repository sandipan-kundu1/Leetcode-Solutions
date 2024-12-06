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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        // Queue to store {node, index}
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long mini = q.front().second; // Minimum index at the current level
            unsigned long long first, last;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front(); // Structured binding
                q.pop();

                // Normalize index to prevent overflow
                index -= mini;

                if (i == 0) first = index;    // First node at this level
                if (i == size - 1) last = index; // Last node at this level

                // Push children with updated indices
                if (node->left) q.push({node->left, index * 2 + 1});
                if (node->right) q.push({node->right, index * 2 + 2});
            }

            // Update the maximum width
            maxWidth = max(maxWidth, static_cast<int>(last - first + 1));
        }

        return maxWidth;
    }
};
