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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode ans(0);
		ListNode* i = l1;
		ListNode* j = l2;
		ListNode* p = &ans;

		while(i!=nullptr && j!=nullptr){
			if(i->val<j->val){
				p->next = i;
				i = i->next;
			}else{
				p->next = j;
				j = j->next;
			}
			p = p->next;
		}

		while(i!=nullptr){
			p->next = i;
			i = i->next;
			p = p->next;
		}
		
		while(j!=nullptr){
			p->next = j;
			j = j->next;
			p = p->next;
		}

		return ans.next;
    }
};