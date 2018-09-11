#include<bits/stdc++.h>
using namespace std;

// 参数:
//        pPush:       压栈序列
//        pPop:        出栈序列
//        nLength:     序列的长度
// 返回值:
//        这两个序列能否匹配
//const位于*的左侧,则const就是用来修饰指针所指向的变量,即指针指向为常量
//如果const位于*的右侧,const就是修饰指针本身,即指针本身是常量
bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	bool bPossible = false;//初始:不能匹配
	//输入合法性检查
	if(pPush != nullptr && pPop != nullptr && nLength > 0) {
		//定义两个用来移动的指针,保留之前的指针用来比较
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;//用一个STL栈来模拟

		//只要没有移动出序列(这两个序列一样长),就要继续判断
		while(pNextPop - pPop < nLength) {
			//栈为空,或者栈内的栈顶元素不是要弹出的元素
			while(stackData.empty() || stackData.top() != *pNextPop) {
				//压栈之前先检查一下,如果所有数字都压入辅助栈了,退出循环
				if(pNextPush - pPush == nLength)
					break;
				//压栈
				stackData.push(*pNextPush);
				//压栈以后,压栈序列的指针要向后走,表示一个元素已经压过栈了
				pNextPush ++;
			}

			//至此,栈内的栈顶元素可能是要弹出的元素
			//还有一种可能就是所有数字都压入辅助栈了

			//总之需要再判断一下栈顶元素是不是弹出序列中要弹出的元素
			if(stackData.top() != *pNextPop)//如果不是
				break;//失败退出

			//至此,一定能正常弹出
			stackData.pop();
			pNextPop ++;//弹出序列向前走,下个循环继续判断
		}

		//循环结束后,通过判断栈内是否清空且弹出序列走完
		if(stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;//就能知道是否成功匹配了
	}

	return bPossible;
}

int main() {
	const int nLength = 5;
	int push[nLength] = {1, 2, 3, 4, 5};
	int pop[nLength] = {3, 5, 4, 2, 1};
	cout<<boolalpha<<IsPopOrder(push,pop,nLength);
	return 0;
}
