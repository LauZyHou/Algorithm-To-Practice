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
        //头插法
        ListNode* ans = new ListNode(0);
        while(head) {
            ListNode* t = head->next;
            head->next = ans->next;
            ans->next = head;
            head = t;
        }
        return ans->next;
    }
};