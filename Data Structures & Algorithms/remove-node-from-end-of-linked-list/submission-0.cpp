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
        if (!head) return nullptr;

        auto* right = head;
        auto* left = head;
        ListNode* prev = nullptr;

        int gap = 0;
        while (right && gap < n) {
            right = right->next;
            gap++;
        }
        while (right && left) {
            right = right->next;
            prev = left;
            left = left->next;
        }
        if (!prev) {
            head = left->next;
            delete left;
        } else {
            auto* next = left->next;
            delete left;
            prev->next = next;
        }

        return head;
    }
};
