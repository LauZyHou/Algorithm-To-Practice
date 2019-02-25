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
	vector<int> preorder(Node* root) {
		stack<Node*> s;
		vector<int> ans;
		if(root==nullptr)
			return ans;
		s.push(root);
		while(!s.empty()){
			root=s.top();
			s.pop();
			ans.push_back(root->val);
			vector<Node*> vn=root->children;
			for(int i=vn.size()-1;i>=0;i--){
				s.push(vn[i]);
			}
		}
		return ans;
	}
};
