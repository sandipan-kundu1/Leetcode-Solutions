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
        vector<ListNode*> vis;
        ListNode* temp=head;
        while(temp){
            if(find(vis.begin(),vis.end(),temp)==vis.end())
            {
                vis.push_back(temp);
                temp=temp->next;
            }
            else
                return true;
            
        }
        return false;
    }
};