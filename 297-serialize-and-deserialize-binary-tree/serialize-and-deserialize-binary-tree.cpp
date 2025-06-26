/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        return "#";

        string s="";
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val)+',';
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(node->left)
                {
                    s+=to_string(node->left->val)+',';
                    q.push(node->left);
                }
                else
                s+="#,";

                if(node->right)
                {
                    s+=to_string(node->right->val)+',';
                    q.push(node->right);
                }
                else
                s+="#,";
            }
        }
        return s;
    }

    string get(string data,int &i,int &j)
    {
        while(j<data.size() && data[j]!=',')
        j++;
        string num=data.substr(i,j-i);
        i=++j;
        return num;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#")
        return NULL;

        int i=0,j=0;
        TreeNode* root;
        root=new TreeNode(stoi(get(data,i,j)));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            string left=get(data,i,j);
            if(left!="#")
            {
                node->left=new TreeNode(stoi(left));
                q.push(node->left);
            }
            
            string right=get(data,i,j);
            if(right!="#")
            {
                node->right=new TreeNode(stoi(right));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));