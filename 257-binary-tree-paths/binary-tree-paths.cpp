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
    void dfs(TreeNode* root,vector<vector<int>>& ans,vector<int>& path)
    {
        if(!root)   return;

        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(path);
        }
        
        dfs(root->left,ans,path);
        dfs(root->right,ans,path);

        path.pop_back();  //poping "root->val"
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root,ans,path);
        vector<string> res;
        for(auto it:ans)
        {
            string s="";
            for(int i=0;i<it.size();i++)
            {
                s+=to_string(it[i]);
                if(i!=it.size()-1)
                {
                    s+="->";
                }
            }
            res.push_back(s);
        }
        return res;
    }
};