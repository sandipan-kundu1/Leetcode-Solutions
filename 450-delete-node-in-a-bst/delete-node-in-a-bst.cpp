/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL)
        return root->right;
        if(root->right==NULL)
        return root->left;

        TreeNode* rightchild=root->right;
        TreeNode* cur=root->left;
        while(cur->right!=NULL)
        {
            cur=cur->right;
        }
        cur->right=rightchild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        TreeNode* dummy = root;
        if (key == root->val) {
            return helper(root);
        }
        while (root) {

            if (key < root->val)
            {
                if(root->left!=NULL && root->left->val==key)
                root->left=helper(root->left);
                else
                root = root->left;
            } 
            else{
                if(root->right!=NULL && root->right->val==key)
                root->right=helper(root->right);
                else
                root = root->right;
            } 
        }
        return dummy;
    }
};