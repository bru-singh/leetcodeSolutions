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
        // Ques: Does the number contains leading zeros?
        // Ques: Do we need to provide the numeber on this reverse order? 
        // or in the correct order for the number
        // Ques: Do we need to provide a new ListNode or we can modify the inputs?


        // Need: current postion value, and carry for the next position
        int curr = 0, carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while(l1 and l2){
            int value = l1->val + l2->val + carry;
            carry = value/10;
            value = value%10;
            ListNode* newNode = new ListNode(value);
            dummy->next = newNode;
            dummy = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int value = l1->val + carry;
            carry = value/10;
            value = value%10;
            ListNode* newNode = new ListNode(value);
            dummy->next = newNode;
            dummy = newNode;
            l1 = l1->next;
        }
        while(l2){
            int value = l2->val + carry;
            carry = value/10;
            value = value%10;
            ListNode* newNode = new ListNode(value);
            dummy->next = newNode;
            dummy = newNode;
            l2 = l2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            dummy->next = newNode;
        }
        // reverse(head);
        return head->next;
    }
};