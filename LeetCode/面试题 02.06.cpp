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
        if(!head || !head->next)
            return true;
        ListNode* s = head;
        ListNode* f = head;
        while(f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        // reverse link
        ListNode* cur = s;
        ListNode* prev = nullptr;
        while(cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        // judge
        ListNode* head2 = prev;
        while(head2 && head) {
            if(head2->val != head->val)
                return false;
            head2 = head2->next;
            head = head->next;
        }
        return true;
    }
};