#include<bits/stdc++.h>
using namespace std;

//三个数找最小 
int Min(int number1, int number2, int number3) {
	int min = (number1 < number2) ? number1 : number2;//min(n1,n2)
	min = (min < number3) ? min : number3;//min(min(n1,n2),n3)
	return min;
}

//输入要寻找的丑数在顺序丑数表中是第几个,计算并返回该丑数 
int GetUglyNumber_Solution(int index) {
	if(index <= 0)//输入合法性 
		return 0;

	int *pUglyNumbers = new int[index];//第index个丑数下标为index-1 
	pUglyNumbers[0] = 1;//1是最小的丑数 
	int nextUglyIndex = 1;//下一个要找的丑数在丑数表中下标 

	//初始化T2,T3,T5的地址,都是&pUglyNumbers[0]
	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	//一直找,找完下标为index-1的,当nextUglyIndex=index时停止 
	while(nextUglyIndex < index) {
		//min(T2,T3,T5)
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;//就是下一个丑数 

		//更新下次T2(的地址):T2*2要刚好大过当前表中最大丑数 
		while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		//更新下次T3(的地址):T3*3要刚好大过当前表中最大丑数 
		while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		//更新下次T5(的地址):T5*5要刚好大过当前表中最大丑数 
		while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;//下次循环要找的丑数下标+1 
	}

	//要找的丑数就是pUglyNumbers[index-1] 
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

int main() {
	cout<<GetUglyNumber_Solution(1500)<<endl;//859963392
	return 0;
}
