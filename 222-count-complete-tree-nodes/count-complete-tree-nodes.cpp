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
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int lh=heightleft(root);
        int rh=heightright(root);
        if(lh==rh)
        return pow(2,lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int heightleft(TreeNode* root)
    {
        if(!root)   return 0;
        int h=0;
        while(root)
        {
            h++;
            root=root->left;
        }
        return h;
    }
    int heightright(TreeNode* root)
    {
        if(!root)   return 0;
        int h=0;
        while(root)
        {
            h++;
            root=root->right;
        }
        return h;
    }
};