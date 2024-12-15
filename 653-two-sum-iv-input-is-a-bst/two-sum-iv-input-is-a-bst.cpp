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
    stack<TreeNode*> st;
    bool isrev=false;
public:
    
    BSTIterator(TreeNode* root,bool reverse) {
        isrev=reverse;
        pushAll(root);
        
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        (isrev)? pushAll(temp->left): pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* node) 
    {
        if (node == nullptr) return;
        while(node)
        {
            st.push(node);
            (isrev)?node=node->right:node=node->left;
            
        }
        return;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root,false);
        BSTIterator right(root,true);
        int a=left.next();
        int b=right.next();
        while(a<b)
        {
            
            if(a+b==k)
            return true;
            else if(a+b<k)
            a=left.next();
            else
            b=right.next();
        }
        return false;
    }
};