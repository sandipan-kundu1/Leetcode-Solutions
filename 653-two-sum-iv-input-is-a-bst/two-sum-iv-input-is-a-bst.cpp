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
 class BSTIterator {
    stack<TreeNode*> s;
    bool forward=true;
    void pushAll(TreeNode* root)
    {
        auto node=root;
        while(node)
        {
            s.push(node);
            node=(forward ? node->left : node->right);
        }
    }
public:
    BSTIterator(TreeNode* root,bool dir) {
        forward=dir;
        pushAll(root);
    }
    
    int next() {
        auto node=s.top();
        s.pop();
        forward? pushAll(node->right) : pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,true);
        BSTIterator r(root,false);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
            return true;
            else if(i+j<k)
            i=l.next();
            else
            j=r.next();
        }
        return false;
    }
};