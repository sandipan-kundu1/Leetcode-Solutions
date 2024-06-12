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
    ListNode* sortList(ListNode* head) {
        // ListNode *temp=head;
        // multiset<int> st;
        // while(temp){
        //     st.insert(temp->val);
        //     temp=temp->next;
        // }
        
        // temp=head;
        // for(auto i=st.begin();i!=st.end();i++){
        //     temp->val= *i;
        //     st.erase(i);
        //     temp=temp->next;
        // }
        // return head;
        if(head==NULL || head->next ==NULL)
        return head;
        
        ListNode *mid= findmid(head);
        ListNode* left=head,*right=mid->next;
        mid->next=nullptr;
        left=sortList(left);
        right=sortList(right);
        return merge2(left,right);
    }

    public: 
    ListNode* merge2(ListNode *head1,ListNode *head2){
        ListNode* temp1=head1,*temp2=head2;
        ListNode* dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
            else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1){
            temp->next=temp1;
            
        }
        else if(temp2){
            temp->next=temp2;
            
        }
        return dummy->next;
    }
    public:
    ListNode *findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        return slow;
    }
};