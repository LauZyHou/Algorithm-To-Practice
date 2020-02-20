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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        for(ListNode* t = head;t!=nullptr;t=t->next) {
            ans = (ans<<1)+t->val;
        }
        return ans;
    }
};