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
    void reorderList(ListNode* head) {
        if (!head) return ;
        // 计算链表长度
        int n = 0;
        for (auto p = head; p; p = p -> next)
            n ++;
        // 找中间的结点
        auto mid = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i ++)
            mid = mid -> next;
        // 翻转后面的部分
        auto a = mid, b = a -> next;
        for (int i = 0; i < n / 2; i ++ ) {
            auto c = b -> next;
            b -> next = a;
            a = b;
            b = c;
        }
        // 至此，a就是翻转后的链表的第一个结点
        // 将翻转后的部分按顺序一个一个插入到左边的链表的每两个结点之间
        auto p = head, q = a; // 两个指针分别指向两个链表的第一个结点
        for (int i = 0; i < n / 2; i ++ ) {
            auto _q = q -> next;
            q -> next = p -> next;
            p -> next = q;
            p = q -> next;
            q = _q;
        }
        if (n & 1)
            mid -> next = nullptr;
        else 
            mid -> next -> next = nullptr;
    }
};