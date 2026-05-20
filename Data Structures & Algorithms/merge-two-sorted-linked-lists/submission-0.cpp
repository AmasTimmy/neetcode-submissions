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
    static ListNode* getElementFromTwoLists(ListNode*& list1, ListNode*& list2) {
        ListNode* node = nullptr;
        if (list1->val >= list2->val) {
            node = list2;
            list2 = list2->next;
        } else {
            node = list1;
            list1 = list1->next;
        }
        return node;
    }

   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2 ? list2 : nullptr;
        if (!list2) return list1 ? list1 : nullptr;

        auto* mergedList = getElementFromTwoLists(list1, list2);
        auto* currentElement = mergedList;
        while (list1 || list2) {
            if (list1 && list2) {
                currentElement->next = getElementFromTwoLists(list1, list2);
            } else {
                if (!list1) {
                    currentElement->next = list2;
                    list2 = list2->next;
                } else if (!list2) {
                    currentElement->next = list1;
                    list1 = list1->next;
                }
            }
            currentElement = currentElement->next;
        }
        return mergedList;
    }
};
