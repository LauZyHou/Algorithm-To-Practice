    /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        dfs(node);

        for (auto [sorce, dest]: hash) {
            for (auto ver: sorce->neighbors) {
                dest->neighbors.emplace_back(hash[ver]);
            }
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);
        for (auto ver: node->neighbors) {
            if (!hash.count(ver))
                dfs(ver);
        }
    }
};