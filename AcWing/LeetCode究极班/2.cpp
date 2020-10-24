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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0); // 虚拟头结点
        auto cur = dummy; // 当前结果链表的指针
        int t = 0; // 进位
        while (l1 || l2 || t) {
            if (l1) {
                t += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                t += l2 -> val;
                l2 = l2 -> next;
            }
            cur -> next = new ListNode(t % 10);
            t /= 10;
            cur = cur -> next;
        }
        return dummy -> next;
    }
};