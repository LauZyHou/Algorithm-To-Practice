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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        ListNode* small = new ListNode(0);
		ListNode* i = small;
		ListNode* big = new ListNode(0);
		ListNode* j = big;
		//ListNode* mid = new ListNode(0);
		//ListNode* m = mid;
		for(ListNode* p=head;p;p=p->next){
			if(p->val<x){
				i->next = p;
				i = p;
			}else{
				j->next = p;
				j = p;
			}
		}

		//防止成环
		j->next = nullptr;
		//连接
		i->next = big->next;
		return small->next;
    }
};