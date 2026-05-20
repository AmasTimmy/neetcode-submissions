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
    static ListNode* reverse(ListNode* current, ListNode* prev) {
        if (!current) return prev;
        auto* next = current->next;
        current->next = prev;
        return reverse(next, current);
    }

   public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
};
