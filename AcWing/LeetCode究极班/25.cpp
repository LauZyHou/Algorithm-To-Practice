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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        for (auto p = dummy; ;) {
            // 测试后面够不够k个点
            auto q = p;
            for (int i = 0; i < k && q; i ++)
                q = q->next;
            if (!q)
                break;
            // 至此，够k个，要两个两个一起翻转k-1次
            auto a = p->next, b = a->next;
            for (int i = 0; i < k - 1; i ++) {
                // 记录一下b后面的c，不然就找不到了
                auto c = b->next;
                b->next = a; // 反向
                a = b, b = c;
            }
            // 翻转完的部分连好
            auto c = p->next;
            c->next = b, p->next = a;
            // p往后走，做下一组
            p = c;
        }
        return dummy->next;
    }
};