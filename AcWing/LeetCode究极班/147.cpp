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
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = new ListNode(-1);
        for (auto p = head; p; ) {
            auto r = p->next;

            auto cur = dummy;
            while (cur->next && cur->next->val <= p->val)
                cur = cur->next;
            p->next = cur->next;
            cur->next = p;

            p = r;
        }
        return dummy->next;
    }
};