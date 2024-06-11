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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA,*t2=headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            
            if(t1==t2)
            return t1;
            if(t1==NULL)
            t1=headB;
            if(t2==NULL)
            t2=headA;
        }
        return t1;

//         int n1 = 0, n2 = 0;
        
//         while (t1) {
//             n1++;
//             t1 = t1->next;
//         }
        
//         while (t2) {
//             n2++;
//             t2 = t2->next;
//         }

//         // Reset pointers to the heads of the lists
//         t1 = headA;
//         t2 = headB;
        
//         // Align the starting points of both lists
//         if (n1 > n2) {
//             return collision(t2, t1, n1 - n2);
//         } else {
//             return collision(t1, t2, n2 - n1);
//         }
//     }
    
// private:
//     ListNode* collision(ListNode* low, ListNode* high, int d) {
//         // Advance the pointer of the longer list by 'd' nodes
//         while (d) {
//             high = high->next;
//             d--;
//         }
        
//         // Traverse both lists together to find the intersection node
//         while (low != high) {
//             low = low->next;
//             high = high->next;
//         }
        
//         // Return the intersection node, or nullptr if there is no intersection
//         return low;
     }
};