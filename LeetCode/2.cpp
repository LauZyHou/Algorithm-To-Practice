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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2)
			return nullptr;
		int jw = 0;
		queue<int> q1,q2;
		for(ListNode* p=l1;p!=nullptr;p=p->next)
			q1.push(p->val);
		for(ListNode* p=l2;p!=nullptr;p=p->next)
			q2.push(p->val);
		ListNode* ans = new ListNode(0);
		ListNode* ret = ans;
		while(!q1.empty() && !q2.empty()) {
			int v1 = q1.front();
			q1.pop();
			int v2 = q2.front();
			q2.pop();
			int levVal = v1+v2+jw;
			ListNode* ln = new ListNode(levVal%10);
			ret->next = ln;
			ret = ret->next;
			jw = levVal/10;
		}
		queue<int> &s = q1.empty() ? q2 : q1;
		while(!s.empty()) {
			int v = s.front();
			s.pop();
			int levVal = v+jw;
			ListNode* ln = new ListNode(levVal%10);
			ret->next = ln;
			ret = ret->next;
			jw = levVal/10;
		}
		while(jw) {
			ListNode* ln = new ListNode(jw%10);
			ret->next = ln;
			ret = ret->next;
			jw =jw/10;
		}
		return ans->next;
    }
};