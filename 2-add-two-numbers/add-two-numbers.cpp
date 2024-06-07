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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* t1=l1;    //Always use dummy node for creating linked list from other LL's operation
        ListNode* t2=l2;
        ListNode* curr=dummy;
        int carry=0,sum;
        while(t1!=NULL || t2!=NULL || carry){
            sum=carry;
            if(t1){
                sum+=t1->val;
                t1=t1->next;
            } 
            
            if(t2){
                sum+=t2->val;
                t2=t2->next;
            }
            
            ListNode* n=new ListNode(sum%10);
            curr->next=n;
            curr=n;
            carry=sum/10;
           
        }
        return dummy->next;
    }
};