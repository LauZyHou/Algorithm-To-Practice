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
    int kthToLast(ListNode* head, int k) {
        ListNode* t = head;
        while(k--){
            t = t->next;
        }
        while(t) {
            t = t->next;
            head = head->next;
        }
        return head->val;
    }
};