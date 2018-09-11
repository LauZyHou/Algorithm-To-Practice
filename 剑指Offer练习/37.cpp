#include<bits/stdc++.h>
#include "../Utilities/BinaryTree.h"
using namespace std;

//传入二叉(子)树的树根,传入反复使用的输出流的引用
void Serialize(const BinaryTreeNode* pRoot, ostream& stream) {
	if(pRoot == nullptr) {//如果这个结点为空
		stream << "$,";//那么也要使用一个特殊记号记录,写入输出流
		return;//空结点没有左右子树,直接返回
	}
	//至此,非空,将其结点的值写入输出流
	stream << pRoot->m_nValue << ',';
	//前序遍历:中-左-右,分别对其左右子树做序列化
	//有别于以前的那些题,这里刻意不做非空校验,因为空也要被序列化记录!
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

//从输入流中尝试读取一个数字,按地址写回
//返回是否成功读取并写回了这样一个数字
bool ReadStream(istream& stream, int* number) {
	if(stream.eof())//如果已经到了输入流结尾
		return false;//不用读了,读不出

	char buffer[32];//用于存储读出来的数据
	buffer[0] = '\0';//开头设为'\0'结束符,这样如果没读出东西也能正常结束

	char ch;
	stream >> ch;//从输入流中读入一个字符
	int i = 0;//游标还是从0开始,如果读出有效字符会覆盖掉前面的'\0'
	//只要没读完输入流,并且没读出的不是分隔符,就一直往下读
	while(!stream.eof() && ch != ',') {
		buffer[i++] = ch;
		stream >> ch;
	}
	//至此,可能已经读出了一些数据,检测是否为数字
	//注意,如果没读出数字,buffer中开头就是'\0'结束符
	bool isNumeric = false;
	//如果读出了有效的字符(i>0),并且读出的不是空结点(buffer[0]!='$')
	if(i > 0 && buffer[0] != '$') {
		*number = atoi(buffer);//把字符串转换成整形,按地址存入
		isNumeric = true;
	}
	//其实直接在if里return true,在if外面return false就好了
	//没必要如此搞个变量记录,这里还是保留作者的写法
	return isNumeric;
}


//递归函数,传入二叉(子)树根结点指针变量的地址,输入流的引用
//对输入流中的东西进行反序列化写入根节点指针中,形成二叉树
void Deserialize(BinaryTreeNode** pRoot, istream& stream) {
	int number;//当前读取到的数字
	//如果能从输入流中成功读取出一个数字到number里
	if(ReadStream(stream, &number)) {
		//说明这次读到了一个真实存在的结点
		//为当前节点分配空间,这里*pRoot就是当前结点的指针(二级指针取了一次地址)
		*pRoot = new BinaryTreeNode();
		//设置值
		(*pRoot)->m_nValue = number;
		//因为是前序遍历,左右子树还在输入流里没读出来,先设置为空
		(*pRoot)->m_pLeft = nullptr;
		(*pRoot)->m_pRight = nullptr;
		//对其左右子树分别反序列化,下面分析一下第一个参数怎么回事
		//这里"(*pRoot)"是取本结点的指针变量
		//然后"->m_pLeft"获取其左孩子域指针
		//然后再取"&"也就得到了本节点的左孩子域指针的地址,可以传入递归函数了
		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

//            8
//        6      10
//       5 7    9  11
int main() {
	//建立一棵二叉树
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	//输出看一下
	BinaryTreeNode* pRoot=pNode8;
	PrintTree(pRoot);
	//将其序列化到文件中
	//[勘误]作者原来写的是char* fileName,这不是C++该有的用法
	char fileName[] = "test.txt"; 
	ofstream fileOut;//ofstream即Output File Stream文件输出流
	//ofstream也是ostream的一种,可以直接传入
	fileOut.open(fileName);//打开文件
	Serialize(pRoot, fileOut);//序列化
	fileOut.close();//关闭文件
	//序列化完成后立即将它在从内存中销毁
	DestroyTree(pNode8);

	//此时,内存中已经没有这棵树了
	cout<<"--------------------------------"<<endl;

	//从文件中反序列化
	ifstream fileIn2;//ifstream即Iutput File Stream文件读入流
	fileIn2.open(fileName);//打开文件 
	BinaryTreeNode* pNewRoot = nullptr;
	Deserialize(&pNewRoot, fileIn2);//读入,传入根节点指针的地址 
	fileIn2.close();//关闭文件 
	//输出看一下
	PrintTree(pNewRoot);
	//销毁 
	DestroyTree(pNewRoot);

	return 0;
}
