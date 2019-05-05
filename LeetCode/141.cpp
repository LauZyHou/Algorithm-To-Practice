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
    bool hasCycle(ListNode *head) {
        if(!head)
			return false;
		ListNode* fast=head;
		ListNode* slow=head;
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
			//fast && slow==fast->next希望能更快速收敛
			if(slow==fast || fast && slow==fast->next)
				return true;
		}
		return false;
    }
};