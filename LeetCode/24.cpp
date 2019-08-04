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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
			return head;
		ListNode* tmp = new ListNode(0);
		tmp->next = head;
		ListNode* p = tmp;
		ListNode* q = head;
		ListNode* r = head->next;
		while(true) {
			p->next = r;
			q->next = r->next;
			r->next = q;
			if(!q->next || !q->next->next)
				break;
			p = q;
			q = p->next;
			r = q->next;
		}
		return tmp->next;
    }
};