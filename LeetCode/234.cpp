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
	ListNode* reverse(ListNode* t) {
		if(!t->next)
			return t;
		ListNode* r = reverse(t->next);
		//此时,t->next恰好是r链的最后一个结点,将其指向这个结点
		t->next->next = t;
		//这时候t和其next是互相指的,把原来的指向(从t到t->next的)断开
		t->next = nullptr;//不然就死循环了
		return r;
	}

	bool isPalindrome(ListNode* head) {
		if(!head || !head->next)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;
		//快慢指针找中间结点,这里fast->next->next是让slow不要超过中间
		while(fast && fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		//通过判断fast指针,就能知道现在是奇数个还是偶数个
		bool odd = fast->next==nullptr;
		//翻转
		ListNode* rev = reverse(slow->next);
		//偶数个,要从头判断到slow
		//奇数个,要从头判断到slow前一个
		while(rev){
			if(rev->val!=head->val)
				return false;
			head = head->next;
			rev = rev->next;
		}
		//奇数个会走到slow,偶数个会走完
		//return odd && head->next==slow || !odd;
		//上式是必然的,不必判断.....
		return true;
	}
};