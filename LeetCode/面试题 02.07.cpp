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
        if(!headA || !headB)
            return nullptr;
        // 后面的结点数
        int lenA = 0;
        int lenB = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA->next) {
            lenA++;
            pA = pA->next;
        }
        while(pB->next) {
            lenB++;
            pB = pB->next;
        }
        if(pA!=pB)
            return nullptr;
        int diff = lenA-lenB;
        pA = headA;
        pB = headB;
        if(diff>0) {
            for(int i=0;i<diff;i++)
                pA = pA->next;
        }else{
            for(int i=0;i<-diff;i++)
                pB = pB->next;
        }
        while(pA!=pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};