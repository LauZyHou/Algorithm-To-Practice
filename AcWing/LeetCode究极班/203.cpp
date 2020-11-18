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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy -> next = head;
        for (auto p = dummy; p; p = p -> next) {
            auto q = p -> next;
            while (q && q -> val == val)
                q = q -> next;
            p -> next = q;
        }
        return dummy -> next;
    }
};