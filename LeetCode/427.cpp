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
	//使用g从x,y开始,偏移ofst的长度,建立四叉树,返回建立后的结点
	Node* quadTree(vector<vector<int>> g,int x,int y,int ofst){
		if(ofst==0)
			return nullptr;
		//判断这一块是不是都是相同,相同就压缩
		for(int i=x;i<x+ofst;i++)
			for(int j=y;j<y+ofst;j++)
				if(g[i][j]!=g[x][y]){//出现了不同,递归地对每一块建立树然后给本节点
					return new Node(false,false,
						quadTree(g,x,y,ofst/2),
						quadTree(g,x,y+ofst/2,ofst/2),
						quadTree(g,x+ofst/2,y,ofst/2),
						quadTree(g,x+ofst/2,y+ofst/2,ofst/2));
				}
		//全部相同,压缩成一个叶子结点
		return new Node((bool)g[x][y],true,nullptr,nullptr,nullptr,nullptr);
	}

    Node* construct(vector<vector<int>>& grid) {
        return quadTree(grid,0,0,grid.size());//grid.size()和grid[0].size()相同
    }
};