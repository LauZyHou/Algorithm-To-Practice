/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
//         先实现中右->左放到vector里,再翻转回来
        stack<Node*> s;
        vector<int> res;
        if(root==nullptr)
            return res;
        s.push(root);
        while(!s.empty()){
            Node* n = s.top();
            s.pop();
            vector<Node*> vn = n->children;
            for(int i=0;i<vn.size();i++){
                s.push(vn[i]);
            }
            res.push_back(n->val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
