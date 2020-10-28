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
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto p = dummy;
        while (p->next) {
            auto q = p->next->next;
            while (q && q->val == p->next->val) {
                q = q->next;
            }
            if (p->next->next == q) {
                p = p->next;
            }
            else {
                p->next = q;
            }
        }
        return dummy->next;
    }
};