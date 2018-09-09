#include "../Utilities/List.h"
#include<bits/stdc++.h>
using namespace std;

//非递归实现反向输出 
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	//创建一个存放结点地址的STL工具栈 
    stack<ListNode*> nodes;

	//从头结点开始 
    ListNode* pNode = pHead;
    while(pNode != nullptr)//直到链表结束,为空 
    {
        nodes.push(pNode);//入栈 
        pNode = pNode->m_pNext;//向后走 
    }

	//只要栈不为空 
    while(!nodes.empty())
    {
        pNode = nodes.top();//取栈顶元素 
        printf("%d\t", pNode->m_nValue);//输出值 
        nodes.pop();//弹出栈顶元素 
    }
}

//递归实现反向输出 
void PrintListReversingly_Recursively(ListNode* pHead)
{
	//这个头结点实际是当前所剩子链表的第一个结点 
    if(pHead != nullptr)
    {
    	//只要后面的结点不为空 
        if (pHead->m_pNext != nullptr)
        {
        	//就将其当做头结点,继续调用这个函数自己形成递归 
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
 		//递归退栈时再输出值,即实现了反向输出 
        printf("%d\t", pHead->m_nValue);
    }
}

int main(){
	//建立结点 
	ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
	//建立连接关系,形成链表 
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	//指定头结点 
	ListNode* pHead=pNode1;
	//调用非递归的 
	PrintListReversingly_Iteratively(pHead);
    printf("\n");
    //调用递归的 
	PrintListReversingly_Recursively(pHead);
	return 0;
}
