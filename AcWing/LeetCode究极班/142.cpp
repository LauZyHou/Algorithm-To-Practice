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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        auto f = head, s = head;
        while (f) {
            s = s->next, f = f->next;
            if (!f) return nullptr;
            f = f->next;
            if (s == f) {
                s = head;
                while (s != f)
                    s = s->next, f = f->next;
                return s;
            }
        }
        return nullptr; // 不会执行
    }
};