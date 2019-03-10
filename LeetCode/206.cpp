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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
			return head;
		ListNode* nd = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return nd;
    }
};