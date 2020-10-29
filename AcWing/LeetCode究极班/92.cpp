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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto a = dummy;
        for (int i = 0; i < m - 1; i ++)
            a = a->next;
        
        // 翻转m~n，共n-m条边
        auto l = a->next, r = l->next;
        for (int i = 0; i < n - m; i ++) {
            auto tmp = r->next;
            r->next = l;
            l = r, r = tmp;
        }

        a->next->next = r;
        a->next = l;
        
        return dummy->next;
    }
};