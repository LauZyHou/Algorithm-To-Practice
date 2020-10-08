/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    pair<ListNode*, ListNode*> rev(ListNode* tail, ListNode* head, ListNode* &newTail, ListNode* &newHead) {
        ListNode* prev = tail -> next;
        ListNode* p = head;
        
        while (prev != tail) {
            ListNode* nex = p -> next;
            p -> next = prev;
            prev = p;
            p = nex;
        }

        return {tail, head};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fst = new ListNode(0);
        fst -> next = head;

        ListNode* pre = fst;
        ListNode* tail = fst;

        while (head) {
            for (int i = 0; i < k; i ++) {
                tail = tail -> next;
                if (tail == nullptr)
                    return fst -> next;
            }

            ListNode* nex = tail -> next;
            ListNode* newTail;
            ListNode* newHead;
            tie(head, tail) = rev(tail, head, newTail, newHead);
            pre -> next = head;
            tail -> next = nex;

            pre = tail;
            head = tail -> next;
        }

        return fst -> next;
    }
};