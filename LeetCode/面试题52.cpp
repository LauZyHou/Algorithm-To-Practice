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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        int diffLen = 0;
        while(p && q) {
            p = p->next;
            q = q->next;
        }
        bool isALong = false; // 记录A和B谁长
        while(p) {
            isALong = true;
            p = p->next;
            diffLen++;
        }
        while(q) {
            q = q->next;
            diffLen++;
        }

        p = headA;
        q = headB;
        while(diffLen--) {
            if(isALong)
                p = p->next;
            else
                q = q->next;
        }
        while(p!=q) { // 最坏到最后正好nullptr
            p = p->next;
            q = q->next;
        }
        return q;
    }
};