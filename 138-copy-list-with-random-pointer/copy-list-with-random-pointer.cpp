/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return NULL;
        
        Node* newnode=new Node(head->val);
        
        unordered_map<Node*,Node*> hash;
        hash[head]=newnode;
        Node* temp=head->next;
        Node* temp1=newnode;
        while(temp)
        {
            Node* n=new Node(temp->val);
            temp1->next=n;
            hash[temp]=n;
            temp=temp->next;
            temp1=temp1->next;
        }
        temp=head;
        temp1=newnode;
        while(temp)
        {
            temp1->random=hash[temp->random];
            temp=temp->next;
            temp1=temp1->next;
        }
        return newnode;
    }
};