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
    int maxDepth(Node* root) {
        if(root==nullptr)
			return 0;
		vector<Node*> vn=root->children;
		if(vn.size()==0)
			return 1;
		int nowlen=maxDepth(vn[0]);
		for(int i=1;i<vn.size();i++){
			int vnilen=maxDepth(vn[i]);
			if(vnilen>nowlen)
				nowlen=vnilen;
		}
		return 1+nowlen;
    }
};