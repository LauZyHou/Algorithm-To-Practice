/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* q1, Node* q2) {
        //两个节点中,有一个是叶子,那么就可以根据叶子的值来判断或之后的结果
		//全True和谁或都是自己,全False和谁或都是对方
		if(q1->isLeaf)
			return q1->val ? q1 : q2;
		if(q2->isLeaf)
			return q2->val ? q2 : q1;
		Node* tl = intersect(q1->topLeft,q2->topLeft);
		Node* tr = intersect(q1->topRight,q2->topRight);
		Node* bl = intersect(q1->bottomLeft,q2->bottomLeft);
		Node* br = intersect(q1->bottomRight,q2->bottomRight);
		//考虑或了之后,四块可能一样bool值的问题
		if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
			if(tl->val && tr->val && bl->val && br->val)
				return new Node(true,true,nullptr,nullptr,nullptr,nullptr);
			else if(!tl->val && !tr->val && !bl->val && !br->val)
				return new Node(false,true,nullptr,nullptr,nullptr,nullptr);
		}
		//四块有不一样的,或者有非叶子,那肯定不能在这一层全一样
		return new Node(false,false,tl,tr,bl,br);
    }
};