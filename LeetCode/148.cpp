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
	ListNode* sortList(ListNode* head) {
		if(!head || !head->next)
			return head;
		ListNode* fast = head->next;//这里一定要先行一步
		ListNode* slow = head;
		while(fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		//断开,得到两个链表
		ListNode* mid = slow->next;
		slow->next = nullptr;
		//递归,得到两个排序后的链表
		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);
		//一个活动指针和一个标志链表头的指针
		ListNode* retpre = new ListNode(0);
		ListNode* p = retpre;
		//遍历两个链表,只要有一个为空就先结束
		while(left && right) {
			if(left->val < right->val) {
				p->next = left;
				left = left->next;
			}
			else {
				p->next = right;
				right = right->next;
			}
			p = p->next;
		}
		//最后有一个链表还没走完
		if(left)
			p->next = left;
		else
			p->next = right;
		return retpre->next;
	}
};