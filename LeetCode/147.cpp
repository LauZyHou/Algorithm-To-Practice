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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* anspre = new ListNode(0);
		ListNode* p = head;
		while(p) {
			ListNode* t = p;
			p = p->next;
			t->next = nullptr;
			ListNode* r = anspre;
			for(;r->next;r=r->next) {
				if((r==anspre || r->val<=t->val) && r->next->val>=t->val)
					break;
			}
			t->next = r->next;
			r->next = t;
		}
		return anspre->next;
    }
};