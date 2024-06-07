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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        // ListNode* odd=head;
        // ListNode* even=head->next;
        // ListNode* evenhead=even;
        // while(even && even->next){
        //     odd->next= odd->next->next;
        //     even->next= even->next->next;
        //     odd=odd->next;
        //     even=even->next;

        // }
        // odd->next= evenhead;

        vector<int> arr;
        ListNode* temp=head;
        while(temp && temp->next){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)
        arr.push_back(temp->val);
        temp=head->next;
        while(temp && temp->next){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)
        arr.push_back(temp->val);
        temp=head;
        int i=0;
        while(temp && i<arr.size()){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};