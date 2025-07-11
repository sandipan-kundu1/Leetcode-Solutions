/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    bool isLeaf(Node* A)
    {
        return !A->left && !A->right;
    }
    void helper(Node* l,Node* r)
    {
        if(!l || !r)    return;
        l->next=r;
        r->next=NULL;
        helper(l->left,l->right);
        helper(l->right,r->left);
        helper(r->left,r->right);
    }
    Node* connect(Node* root) {
        if(!root)  return root;
        root->next=NULL;
        if(isLeaf(root))
            return root;
        
        helper(root->left,root->right);
        return root;
    }
};