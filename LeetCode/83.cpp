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
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p=head;
		ListNode* now=p;
		while(p){
			while(now && now->val==p->val){
				now=now->next;
			}
			p->next=now;
			p=now;
		}
		return head;
    }
};