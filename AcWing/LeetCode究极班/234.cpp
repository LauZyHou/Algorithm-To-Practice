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
    bool isPalindrome(ListNode* head) {
        // 先计算一下链表中结点的数量
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        if (n <= 1) return true;
        // 翻转链表的后一半，一共要翻转half-1次
        int half = n / 2;
        auto a = head;
        for (int i = 0; i < n - half; i ++ ) // 注意这里是n - half
            a = a->next;
        auto b = a->next;
        for (int i = 0; i < half - 1; i ++ ) { // 注意翻转的地方是half - 1
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        // 翻转完成后b指向nullptr，a则指向最后一个元素
        // 双指针判断是否是回文串
        auto p = head, q = a;
        bool succ = true;
        for (int i = 0; i < half; i ++ ) { // 注意双指针判断的地方是half
            if (p->val != q->val) {
                succ = false;
                break;
            }
            p = p->next;
            q = q->next;
        }
        // 最后将链表恢复原状
        auto tail = a;
        b = a->next;
        for (int i = 0; i < half - 1; i ++ ) { // 注意翻转的地方是half - 1
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        tail->next = nullptr;
        return succ;
    }
};