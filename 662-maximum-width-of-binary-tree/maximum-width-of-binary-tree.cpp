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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0}); //node,index
        long long maxwidth=0;
        while(!q.empty())
        {
            int size=q.size();
            long long start=q.front().second;
            long long end=q.back().second;
            maxwidth=max(maxwidth,end-start+1);
            for(int i=0;i<size;i++)
            {
                auto [node,ind]=q.front();
                q.pop();               
                ind=ind-start;//this used to stop overflow of index, so reducing parent by start
                if(node->left)
                q.push({node->left,2*ind+1});//each level starts from 0*2+1=1
                if(node->right)
                q.push({node->right,2*ind+2});
            }
        }
        return (int)maxwidth;
    }
};