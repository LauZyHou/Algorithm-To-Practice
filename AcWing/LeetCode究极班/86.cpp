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
    ListNode* partition(ListNode* head, int x) {
        auto lh = new ListNode(-1), rh = new ListNode(-1);
        auto lt = lh, rt = rh;

        for (auto p = head; p; p = p->next) {
            if (p->val < x)
                lt = lt->next = p;
            else
                rt = rt->next = p;
        }
        
        lt->next = rh->next;
        rt->next = nullptr;

        return lh->next;
    }
};