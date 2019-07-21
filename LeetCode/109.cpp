/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* traceback(ListNode* h) {
		//递归出口
		if(!h)
			return nullptr;
		//快慢指针找到中间结点,另外还要设一个跟随慢指针找到中间结点的前一个节点
		//找这个节点是为了将链表从中间位置断开
		ListNode* follow = nullptr;
		ListNode* slow = h;
		ListNode* fast = h;

		while(fast && fast->next) {
			follow = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		//断开
		if(follow)
			follow->next = nullptr;

		//以中间结点建立根节点,左右孩子递归调用
		TreeNode* ret = new TreeNode(slow->val);
		ret->left = follow==nullptr ? nullptr : traceback(h);
		ret->right = traceback(slow->next);
		return ret;
	}

    TreeNode* sortedListToBST(ListNode* head) {
        return traceback(head);
    }
};