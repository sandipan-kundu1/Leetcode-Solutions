/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    ListNode* rev(ListNode* temp){
        if(temp==NULL || temp->next==NULL)
         return temp;

        ListNode* newhead=reverseList(temp->next);
        ListNode* front=temp->next;
        front->next=temp;
        temp->next=NULL;
        return newhead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        return rev(temp);

        // if(head==NULL || head->next==NULL)
        // return head;
        // ListNode *curr=head,*nextnode=head,*prevnode=NULL;
        // while(curr){
        //     nextnode=curr->next;
        //     curr->next=prevnode;
        //     prevnode=curr;
        //     curr=nextnode;
        // }
        // return prevnode;
    }
};