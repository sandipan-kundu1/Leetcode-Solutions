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
    vector<int> inorderTraversal(TreeNode* root) {//left print right
        vector<int> ans;
        if(!root)   return ans;
        auto cur=root;
        while(cur)
        {
            if(!cur->left)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                auto prev=cur->left;
                while(prev->right && prev->right!=cur)
                prev=prev->right;

                if(!prev->right)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else if(prev->right==cur)
                {
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};