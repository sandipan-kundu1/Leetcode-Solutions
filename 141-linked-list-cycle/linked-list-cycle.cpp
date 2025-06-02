/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* slow,*fast;
        slow=head;
        fast=head->next;
        while(slow!=fast){
            if(!fast)
                return false;
            slow=slow->next;
            if(fast->next!=NULL)
            fast=fast->next->next;
            else
                return false;
        }
        return true;
    }
};