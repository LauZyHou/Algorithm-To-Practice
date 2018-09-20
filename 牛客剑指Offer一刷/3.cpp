#include<bits/stdc++.h>
using namespace std;

//反转链表成数组
//通过不了,难道不能改原链表?见3-2 

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(nullptr) {
      }
};


class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* nowHead=head;//1
        ListNode* nowNext=head->next;//2
        
        nowHead->next=nullptr;//***
        
        ListNode* nowNN=nullptr;
		vector<int> v;
        while(nowNext!=nullptr){
        	nowNN=nowNext->next;//3
        	
			nowNext->next=nowHead;
			nowHead=nowNext;
			nowNext=nowNN;
		}
		
		while(nowHead!=nullptr){
			v.push_back(nowHead->val);
			nowHead=nowHead->next;
		}
		
		return v;
    }
}; 


int main(){
	ListNode* l1=new ListNode(1);
	ListNode* l2=new ListNode(2);
	ListNode* l3=new ListNode(3);
	ListNode* l4=new ListNode(4);
	
	l1->next=l2;
	l2->next=l3;
	l3->next=l4;
	
	Solution s;
	vector<int> v=s.printListFromTailToHead(l1);
	
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	
	return 0;
}

