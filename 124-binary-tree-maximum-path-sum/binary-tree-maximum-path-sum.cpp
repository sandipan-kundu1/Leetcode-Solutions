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
    int maxpath(TreeNode* root,int &maxi)
    {
        if(!root)   return 0;

        int lsum=maxpath(root->left,maxi);
        int rsum=maxpath(root->right,maxi);
        if(lsum<0)  lsum=0;
        if(rsum<0)  rsum=0;
        maxi=max(maxi,root->val+lsum+rsum);
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxpath(root,maxi);
        return maxi;
    }
};