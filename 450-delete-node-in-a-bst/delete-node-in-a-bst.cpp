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
    TreeNode* helper(TreeNode* root)
    {
        if(!root->right)
        return root->left;
        if(!root->left)
        return root->right;

        TreeNode* leftChild=root->left;
        auto leftmost=root->right;

        while(leftmost->left)
        leftmost=leftmost->left;//finding leftmost node of right subtree

        leftmost->left=leftChild;
        return root->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return NULL;

        if(root->val==key)
        return helper(root);
        TreeNode* temp=root;
        while(temp)
        {
            if(temp->val<key)
            {
                if(temp->right && temp->right->val==key)
                {
                    temp->right=helper(temp->right);
                    break;
                }
                else
                temp=temp->right;
            }
            else if(temp->val>key)
            {
                if(temp->left && temp->left->val==key)
                {
                    temp->left=helper(temp->left);
                    break;
                }
                else
                temp=temp->left;
            }
        }
        return root;
    }
};