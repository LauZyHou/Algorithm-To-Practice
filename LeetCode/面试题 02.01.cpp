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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head)
            return nullptr;
        set<int> st;
        st.insert(head->val);
        ListNode* p = head;
        ListNode* q = head->next;
        while(q) {
            if(st.count(q->val)) {
                p->next = q->next;
                q = q->next;
            } else {
                st.insert(q->val);
                p = q;
                if(!p)
                    break;
                q = q->next;
            }
        }
        return head;
    }
};