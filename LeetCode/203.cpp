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
    ListNode* removeElements(ListNode* head, int val) {
		while(head!=nullptr && head->val==val)
			head = head->next;
		if(!head)
			return nullptr;
		ListNode* p = head;
		ListNode* q = head->next;
		while(q!=nullptr){
			if(q->val==val){
				p->next = q->next;
				q = q->next;
			} else{
				p = q;
				q = q->next;
			}
		}
		return head;
    }
};