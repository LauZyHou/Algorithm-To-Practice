/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
		if(!head)
			return nullptr;
        ListNode* p = head;
		ListNode* r = p->next;
		for(;r;r=r->next){
			if(r->val!=p->val){
				p->next = r;
				p = r;
			}
		}
		p->next = nullptr;
		return head;
    }
};