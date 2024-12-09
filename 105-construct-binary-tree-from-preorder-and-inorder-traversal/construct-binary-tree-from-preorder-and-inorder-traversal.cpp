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
 #define T TreeNode*
class Solution {
public:
    T build(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,unordered_map<int,int> &inmap)
    {
        if(prestart>preend || instart>inend)
        return NULL;

        TreeNode* root=new TreeNode(preorder[prestart]);
        
        int inroot=inmap[root->val];
        int inleft=inroot-instart;
        root->left=build(preorder,prestart+1,prestart+inleft,inorder,instart,inroot-1,inmap);
        root->right=build(preorder,prestart+inleft+1,preend,inorder,inroot+1,inend,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(inorder.size()!=preorder.size())
        return NULL;
        int size=preorder.size();
        
        unordered_map<int,int> inmap;
        for(int i=0;i<inorder.size();i++)
        inmap[inorder[i]]=i;

        return build(preorder,0,size-1,inorder,0,size-1,inmap);
        
        
    }
};