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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                //cycle detect

                slow = head;
                // start point of the cycle
                // x1+ x2 -- distance by slow
                // x1 + x2 + x3 + x2 -- distance by fast
                // 2(x1+x2)==x1 + x2 + x3 + x2;
                // x1= x3;
                // that is why we move one pointer to the start and continue one from the
                // meeting point to find the start of the cycle
                
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};