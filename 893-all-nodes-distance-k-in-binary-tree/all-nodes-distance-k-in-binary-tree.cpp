/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void dfs(TreeNode* root)
    {
        if(!root)   return;
        if(!root->left && !root->right) return;
        if(root->left)
        parent[root->left]=root;
        if(root->right)
        parent[root->right]=root;

        dfs(root->left);
        dfs(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        for(int i=0;i<k;i++)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }  
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=true;
                } 
                if(node!=root && !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }  
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();

        }
        return res;
    }
};