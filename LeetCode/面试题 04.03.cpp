/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<ListNode*> listOfDepth(TreeNode* t) {
        vector<ListNode*> ans;
        if(!t)
            return ans;
        queue<TreeNode*> q;
        ListNode* head = new ListNode(0);
        q.push(t);
        while(q.size()) {
            int len = q.size();
            ListNode* p = head;
            for(int i=0;i<len;i++) {
                TreeNode* a = q.front();
                p->next = new ListNode(a->val);
                p = p->next;
                q.pop();
                if(a->left)
                    q.push(a->left);
                if(a->right)
                    q.push(a->right);
            }
            ans.push_back(head->next);
        }
        return ans;
    }
};