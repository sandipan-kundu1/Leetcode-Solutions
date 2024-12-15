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
    TreeNode* first=new TreeNode();
    TreeNode* middle=new TreeNode();
    TreeNode* last=new TreeNode();
    TreeNode* prev=new TreeNode();
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        return;
        inorder(root->left);

        if(prev!=NULL && root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else{
                last=root;
                return;
            }
            
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=middle=last=prev=NULL;
        inorder(root);
        if(first && last)
        swap(first->val,last->val);
        else
        swap(first->val,middle->val);
    }
};