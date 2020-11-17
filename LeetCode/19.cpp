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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        auto dummy = new ListNode(0);
        dummy -> next = head;
        
        auto p1 = dummy, p2 = dummy;
        for (int i = 0; i < k + 1; i ++) {
            p2 = p2 -> next;
        }
        while (p2) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        p1 -> next = p1 -> next -> next;
        return dummy -> next;
    }
};