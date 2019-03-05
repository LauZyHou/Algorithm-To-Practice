/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = nullptr;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        if(head==nullptr || head->next==nullptr)
			return head;
		ListNode* now = head->next;
		ListNode* pre = head;
		ListNode* nex = head->next->next;
		head->next = nullptr;//关键!否则形成环造成判题时TLE
		while(true){
			now->next = pre;
			if(nex==nullptr)
				break;
			pre = now;
			now = nex;
			nex = nex->next;
		}
		return now;
	}
};