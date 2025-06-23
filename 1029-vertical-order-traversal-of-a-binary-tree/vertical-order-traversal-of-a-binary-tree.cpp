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
    map<int,map<int,multiset<int>>> data; //vertical,level,nodes val

    void inorder(TreeNode* root,int vertical,int level)
    {
        if(!root)   return;
        data[vertical][level].insert(root->val);
        inorder(root->left,vertical-1,level+1);
        inorder(root->right,vertical+1,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        inorder(root,0,0);
        for(auto &it:data)
        {
            vector<int> line;
            for(auto &level:it.second)
            {
                for(auto &s:level.second)
                line.push_back(s);
            }
            ans.push_back(line);
        }
        return ans;
    }
};