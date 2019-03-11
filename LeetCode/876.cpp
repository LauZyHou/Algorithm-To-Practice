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
    ListNode* middleNode(ListNode* head) {
		if(head==nullptr || head->next==nullptr)
			return head;
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast->next!=nullptr && fast->next->next!=nullptr){
			slow = slow->next;
			fast = fast->next->next;
		}
		if(fast->next==nullptr)
			return slow;
		else
			return slow->next;
    }
};