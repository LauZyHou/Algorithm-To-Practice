/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 在每个结点后面插入一个复制的结点
        for (auto p = head; p; p = p->next->next) {
            auto q = new Node(p->val);
            q -> next = p->next;
            p -> next = q;
        }

        // 复制random指针
        for (auto p = head; p; p = p->next->next) {
            if (p->random)
                p->next -> random = p->random->next;
        }

        // 用新的临时链表把next指针串起来，并恢复原链表的next指针
        auto dummy = new Node(-1), tail = dummy;
        for (auto p = head; p; p = p -> next) {
            tail = tail -> next = p->next;
            p -> next = tail->next;
        }
        return dummy->next;
    }
};