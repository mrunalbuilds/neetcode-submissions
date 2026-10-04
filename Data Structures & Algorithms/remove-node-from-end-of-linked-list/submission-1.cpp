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
        //do it in one pass
        ListNode *first = head;
        for(int i=0;i<n;i++){
            first = first->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* second = dummy;
        while(first != nullptr){
            second = second->next;
            first = first->next;
        }

        second->next = second->next->next;

        return dummy->next;


    }
};
