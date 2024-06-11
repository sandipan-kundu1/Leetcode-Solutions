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

        ListNode* newhead=rev(temp->next);
        ListNode* front=temp->next;
        front->next=temp;
        temp->next=NULL;
        return newhead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        return true;
        ListNode *slow=head,*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=rev(slow->next);
        slow->next=newhead;
        ListNode* first=head, *second=newhead;
        while(second!=NULL){
            if(first->val!=second->val){
                slow->next=rev(newhead);
                return false;
            }
            
            first=first->next;
            second=second->next;
        }
        rev(newhead);
        return true;
    }
};