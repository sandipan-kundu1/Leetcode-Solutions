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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(auto i:lists){
            ListNode* temp=i;
            while(temp!=NULL){
                minheap.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode *dummy=new ListNode(-1);
        ListNode* tem=dummy;
        while(minheap.size()>0){
            ListNode* n=new ListNode(minheap.top());
            tem->next=n;
            tem=n;
            minheap.pop();
        }
        return dummy->next;
    }
};