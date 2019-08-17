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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* p = head;
		if(!p)
			return nullptr;
		ListNode* q = p->next;
		if(!q)
			return head;
		ListNode* hd = p;
		ListNode* hd2 = q;
		while(p->next) {
			p->next = q->next;
			if(p->next)
				p = p->next;
			else
				break;
			q->next = p->next;
			q = q->next;
		}
		p->next = hd2;
		return hd;
    }
};