//二叉树结点结构体 
struct BinaryTreeNode 
{
    int                    m_nValue;//结点的值 
    BinaryTreeNode*        m_pLeft;//左子树地址 
    BinaryTreeNode*        m_pRight;//右子树地址 
};

//传入结点的值,创建一个二叉树结点 
BinaryTreeNode* CreateBinaryTreeNode(int value);
//连接结点,给出父节点和左右子树结点 
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
//输出指定的二叉树结点 
void PrintTreeNode(const BinaryTreeNode* pNode);
//给出根节点,输出整棵二叉树 
void PrintTree(const BinaryTreeNode* pRoot);
//给出根节点,删除整棵二叉树 
void DestroyTree(BinaryTreeNode* pRoot);
