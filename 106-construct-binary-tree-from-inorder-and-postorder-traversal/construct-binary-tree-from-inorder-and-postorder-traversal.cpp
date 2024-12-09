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
    TreeNode* build(vector<int>& inorder,int instart,int inend,vector<int>& postorder,int poststart,int postend,unordered_map<int, int>& inmap)
    {
        if(instart>inend || poststart>postend)
        return NULL;

        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=inmap[root->val];
        int inleft=inroot-instart;
        root->left=build(inorder, instart, inroot - 1,postorder,poststart,poststart+inleft-1, inmap);
        root->right=build(inorder, inroot + 1, inend,postorder,poststart+inleft ,postend-1, inmap);
        return root;
    } 

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() != inorder.size())
            return nullptr;
        int size=inorder.size();
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        return build(inorder,0,size-1,postorder,0,size-1,inmap);
    }
};