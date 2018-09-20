#include<bits/stdc++.h>
using namespace std;

//反转链表成数组
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};
*/

class Solution {
	public:
		vector<int> printListFromTailToHead(ListNode* head) {
			vector<int> v;
			stack<int> s;
			while(head!=nullptr){
				s.push(head->val);
				head=head->next;
			}
			
			while(!s.empty()){
				v.push_back(s.top());
				s.pop();
			}
			
			return v;
		}
};
