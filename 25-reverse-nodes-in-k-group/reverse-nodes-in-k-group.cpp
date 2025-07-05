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
    ListNode* reverse(ListNode* head,int k,ListNode* &ngh)
    {
        if(!head->next)
        return head;
        int count=0;
        ListNode* check=head;
        while(check && count<k)
        {
            check=check->next;
            count++;
        }
        if(count<k)
        {
            ngh=NULL;
            return head;
        }
        count=0;
        ListNode* prev=NULL,*cur=head,*next=NULL;
        while(cur && count<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        ngh=cur;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head->next || k==1) return head;
        ListNode* prevTail=NULL,*nextGroupHead=NULL,*temp=head,*newHead=NULL;
        while(temp)
        {
            ListNode* groupHead=temp;
            ListNode* reverseHead=reverse(groupHead,k,nextGroupHead);
            if (reverseHead == groupHead) {
                if (prevTail) prevTail->next = groupHead;
                break;
            }
            if(!newHead)
            newHead=reverseHead;
            if(prevTail)
            prevTail->next=reverseHead;
            prevTail=temp;
            temp=nextGroupHead;
        }
        return newHead?newHead:head;
    }
};