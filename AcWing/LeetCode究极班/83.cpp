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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        auto cur = head;
        for (auto p = head->next; p; p = p->next) {
            if (p->val != cur->val) {
                cur->next = p;
                cur = p;
            }
        }
        cur->next = nullptr;
        return head;
    }
};