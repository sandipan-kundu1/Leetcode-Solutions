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
    unordered_map<int,int> hash;
    void build(TreeNode* &root,int instart,int inend,int prestart,int preend,vector<int>& preorder, vector<int>& inorder)
    {
        if(instart>inend || prestart>preend)
        return;

        root=new TreeNode(preorder[prestart]);
        int idx=hash[root->val];    //root's index in inorder
        int inleft=idx-instart;

        build(root->left,instart,idx-1,prestart+1,prestart+inleft,preorder,inorder);
        build(root->right,idx+1,inend,prestart+inleft+1,preend,preorder,inorder);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            hash[inorder[i]]=i;
        }
        build(root,0,n-1,0,n-1,preorder,inorder);
        return root;
    }
};