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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            TreeNode* temp=new TreeNode(val);
            root=temp;
            return root;
        }
        TreeNode* cur=root;
        while(true)
        {
            if(val<cur->val)
            {
                if(!cur->left)
                {
                    TreeNode* temp=new TreeNode(val);
                    cur->left=temp;
                    break;
                }
                else
                cur=cur->left;
            }
            else
            {
                if(!cur->right)
                {
                    TreeNode* temp=new TreeNode(val);
                    cur->right=temp;
                    break;
                }
                else
                cur=cur->right;
            }
        }
        return root;
    }
};