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
        ListNode *temp=head;
        multiset<int> st;
        while(temp){
            st.insert(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        for(auto i=st.begin();i!=st.end();i++){
            temp->val= *i;
            st.erase(i);
            temp=temp->next;
        }
        return head;
    }
};