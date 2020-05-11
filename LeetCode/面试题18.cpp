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
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head)
            return nullptr;
        if(head->val == val)
            head = head->next;
        else {
            ListNode* p = head;
            ListNode* q = head->next;
            while(q) {
                if(q->val == val) {
                    p->next = q->next;
                    break;
                }
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};