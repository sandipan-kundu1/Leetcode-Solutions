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
    void inorder(TreeNode* root, int &rank,int k,int &val)
    {
        if(root==NULL)
        return ;

        inorder(root->left,rank,k,val);
        rank++;
        if(rank==k)
        {
            val=root->val;
            return;
        }
        
        inorder(root->right,rank,k,val);

    }
    int kthSmallest(TreeNode* root, int k) {
        int rank=0,val=-1;
        inorder(root,rank,k,val);
        return val;
    }
};