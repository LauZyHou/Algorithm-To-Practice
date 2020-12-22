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
    // 翻转链表
    ListNode* reverse(ListNode* head) {
        auto a = head, b = head -> next;
        while (b) {
            auto c = b -> next;
            b -> next = a;
            a = b, b = c;
        }
        head -> next = nullptr;
        return a;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        auto dummy = new ListNode(-1);
        // 高精度加法
        int t = 0;
        while (l1 || l2 || t) {
            if (l1) { t += l1->val; l1 = l1->next; }
            if (l2) { t += l2->val; l2 = l2->next; }
            auto cur = new ListNode(t % 10);
            cur->next = dummy->next;
            dummy->next = cur;
            t /= 10;
        }
        return dummy->next;
    }
};