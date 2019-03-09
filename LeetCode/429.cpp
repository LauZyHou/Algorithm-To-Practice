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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
		if(root==nullptr)
			return ans;
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			vector<int> hori;//这一层的子vector
			int n = q.size();//这一层的节点数目
			for(int i=0;i<n;i++){
				Node* nd = q.front();
				hori.push_back(nd->val);
				for(auto child : nd->children)
					q.push(child);
				q.pop();
			}
			ans.push_back(hori);
		}
		return ans;
    }
};