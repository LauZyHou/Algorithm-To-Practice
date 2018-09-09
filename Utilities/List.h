//链表结点结构体 
struct ListNode
{
    int       m_nValue;//结点的值 
    ListNode* m_pNext;//指向下一结点的指针 
};

//给定结点值,创建结点并返回新结点地址 
ListNode* CreateListNode(int value);
//连接两个结点,使后一个结点成为前一个结点的next结点 
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
//输出结点 
void PrintListNode(ListNode* pNode);
//给定头结点,输出整个链表 
void PrintList(ListNode* pHead);
//销毁整个链表 
void DestroyList(ListNode* pHead);
//给定一个值,添加新结点到链表尾部 
void AddToTail(ListNode** pHead, int value);
//给定一个值,删除该值对应的链表结点 
void RemoveNode(ListNode** pHead, int value);
