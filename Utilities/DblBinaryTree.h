struct BinaryTreeNode
{
    double                 m_dbValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(double dbValue);

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

void DestroyTree(BinaryTreeNode* pRoot);


