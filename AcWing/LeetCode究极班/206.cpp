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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        auto a = head, b = head -> next;
        while (b) {
            auto c = b -> next;
            b -> next = a;
            a = b, b = c;
        }
        head -> next = nullptr;
        return a;
    }
};