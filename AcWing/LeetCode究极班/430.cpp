/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto res = dfs(head); // 会返回头节点和尾结点
        return res[0]; // 答案就是头节点
    }

    vector<Node*> dfs(Node* head) {
        if (!head) return {nullptr, nullptr};
        // 从前往后遍历整个链表
        auto cur = head, tail = head; // cur是当前遍历的结点，遍历过程中顺便求尾结点tail
        while (cur) {
            tail = cur;
            if (cur -> child) {
                auto t = dfs(cur -> child);
                cur -> child = nullptr; // 注意要清空child域
                t[1] -> next = cur -> next;
                if (cur -> next) {
                    cur -> next -> prev = t[1];
                }
                cur -> next = t[0];
                t[0] -> prev = cur;
                cur = t[1] -> next;
                tail = t[1];
            }
            else
                cur = cur -> next;
        }
        return {head, tail};
    }
};