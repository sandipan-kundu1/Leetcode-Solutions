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
    TreeNode* build(int instart,int inend,int prestart,int preend,vector<int>& preorder, vector<int>& inorder)
    {
        if(instart>inend || prestart>preend)
        return NULL;

        TreeNode* root=new TreeNode(preorder[prestart]);
        int idx=hash[root->val];    //root's index in inorder
        int inleft=idx-instart;

        root->left=build(instart,idx-1,prestart+1,prestart+inleft,preorder,inorder);
        root->right=build(idx+1,inend,prestart+inleft+1,preend,preorder,inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            hash[inorder[i]]=i;
        }
        return build(0,n-1,0,n-1,preorder,inorder);
    }
};