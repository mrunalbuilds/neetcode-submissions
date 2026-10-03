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
    void reorderList(ListNode* head) {
        //1. Find middle
        // 2. Separate the lists
        // 3. Reverse second list
        // 4. Repeatedly:
        //       save first->next
        //       save second->next
        //       connect first → second
        //       connect second → saved first
        //       move both pointers

        //find middle
        ListNode *first = head;
        ListNode *second = head;
        while(second != nullptr && second->next != nullptr){
            first = first->next;
            second = second->next->next;
        }

        second = first->next;
        first->next = nullptr;

        //reverse second half
        ListNode* node = nullptr;
        ListNode* curr = second;
        while(curr != nullptr){
            ListNode *next = curr->next;
            curr->next = node;
            node = curr;
            curr = next;
        }

        second = node;

        //merge
        first = head;
        while(second != nullptr){
            ListNode *dummy = first->next;
            ListNode *dummy2 = second->next;
            first->next = second;
            second->next = dummy;
            first = dummy;
            second = dummy2;

        }
    }
};
