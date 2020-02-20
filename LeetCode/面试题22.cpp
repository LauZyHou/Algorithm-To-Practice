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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        for(int i=0;i<k;i++)
             p2 = p2->next;
        while(p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};