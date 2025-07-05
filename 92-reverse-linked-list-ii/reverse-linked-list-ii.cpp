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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next || left==right)  return head;
        int pos=1;
        ListNode *prevTail=NULL,*temp=head;
        while(temp && pos<left)
        {
            prevTail=temp;
            temp=temp->next;
            pos++;
        }
        pos++;
        ListNode *prev=temp,*cur=temp->next,*next=NULL;
        while(cur && pos<=right)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            pos++;
        }
        //After reverse, linking both ends with the original LL
        if(!prevTail)   
        head=prev;
        else
        prevTail->next=prev; //as prev acts as the reversehead
        temp->next=cur; //as cur points to the next element out of the zone
        //temp initially pointed to head of the zone, which is now reverseTail
        return head;
    }
};