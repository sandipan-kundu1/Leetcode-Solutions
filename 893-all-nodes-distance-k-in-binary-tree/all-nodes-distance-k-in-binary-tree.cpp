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
    void addparent(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent)
    {
        if(root==NULL)
        return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){ parent[temp->left]=temp;  q.push(temp->left);}
                
                if(temp->right) { parent[temp->right]=temp;  q.push(temp->right);}
            
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(root==NULL)
        return res;
        unordered_map<TreeNode*, TreeNode*> parent;
        addparent(root,parent);
        int dis=0;
        queue<TreeNode*> qu;
        qu.push(target);
        int flag=0;
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        while(!qu.empty())
        {
            int size=qu.size();
            flag=0;
            if(dis==k)
            break;
            for(int i=0;i<size;i++)
            {
                TreeNode* t=qu.front();
                qu.pop();
                if(t->left && !visited[t->left])
                {
                    flag=1;
                    qu.push(t->left);
                    visited[t->left]=true;
                }
                if(t->right && !visited[t->right])
                {
                    flag=1;
                    qu.push(t->right);
                    visited[t->right]=true;
                }
                if(parent[t] && !visited[parent[t]])
                {
                    flag=1;
                    qu.push(parent[t]);
                    visited[parent[t]]=true;
                }
            }
            if(flag)
            dis++;
        }

        while(!qu.empty())
        {
            res.push_back(qu.front()->val);
            qu.pop();
        }
        return res;
    }
};