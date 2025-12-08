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
    int getDecimalValue(ListNode* head) {
        // we dont need to reverse the linked list, or start from the
        // least significant bit to the most, 
        // well that logics can work, but they are not the most optimal
        // ways to solve this

        // iterate from the start to the end of the ll, and compute the number by this: 
        // number = 2*number + ll_node->val;

        int number = 0;
        while(head){
            // basically right shift the number
            number = 2*number + head->val;
            head = head->next;
        }
        return number;
    }
};