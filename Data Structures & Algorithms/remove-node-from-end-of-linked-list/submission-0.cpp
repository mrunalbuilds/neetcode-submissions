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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //find the length
        //remove the element length-n
        //have a pointer with prev as well

        int length = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        // 2. Find the position of node to remove
        int position = length - n;

        // 3. Special case: remove head
        if (position == 0) {
            return head->next;
        }

        // 4. Go to the node before the target
        curr = head;

        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;

    }
};
