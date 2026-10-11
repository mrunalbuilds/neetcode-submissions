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
        //just iterate through each linked list
        //have int to carry the one digit
        ListNode *new1 = l1;
        ListNode *new2 = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;
        while(new1 != nullptr || new2 != nullptr || carry != 0){
            int sum = carry;
            if (new1 != nullptr) {
                sum += new1->val;
                new1 = new1->next;
            }

            if (new2 != nullptr) {
                sum += new2->val;
                new2 = new2->next;
            }

            carry = sum/10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};
