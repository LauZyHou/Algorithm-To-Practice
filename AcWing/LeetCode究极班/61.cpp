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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        // 求链表长度，并取得尾结点
        ListNode* tail;
        int n = 0;
        for (auto p = head; p; p = p->next) {
            tail = p;
            n ++;
        }
        // 对长度取模
        k %= n;
        if (!k) return head;
        // 求第n-k个结点，即新链表的最后一个结点
        auto p = head;
        for (int i = 0; i < n - k - 1; i ++)
            p = p->next;
        // 变换
        tail->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};