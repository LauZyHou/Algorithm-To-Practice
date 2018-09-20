#include<bits/stdc++.h>
using namespace std;

int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

//1~n中1出现的次数 
int NumberOf1Between1AndN(int n) {
	if(n <= 0)//输入合法性检查 
		return 0;

	char strN[50];
	sprintf(strN, "%d", n);//输入到字符串中 

	return NumberOf1(strN);//调用递归函数求解 
}

//递归函数:给出字符(子)串strN表示数n,求1~n中各数中数位1出现次数 
int NumberOf1(const char* strN) {
	//输入不合法或者空串时,是没有1的 
	if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;//即0个1,这也是一种递归出口 

	int first = *strN - '0';//开头第一个数字 
	//static_cast<T>(表达式)将表达式转换为T类型, 
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if(length == 1 && first == 0)//单个0 
		return 0;//就没有1 

	if(length == 1 && first > 0)//单个非0一位数字 
		return 1;//从1到任意一个非0一位数字就是一个1 

	/*假设strN是"21345"*/
	/*[A]numFirstDigit是数字10000-19999的第一个位中1的数目*/
	int numFirstDigit = 0;//记录1出现在最高位的次数 
	if(first > 1)//如果最高位不是1
		//那么肯定有完整地[1后跟长度-1个0,1后跟长度-1个9]这样1后跟长度-1个0个数字
		//这些数字的最高位都有个1,即最高位有10的长度-1次方个1 
		numFirstDigit = PowerBase10(length - 1);
	else if(first == 1)//如果最高位是1 
		//那么最高位是1的数字只有末尾的一些,从10..0~最后一个数 
		numFirstDigit = atoi(strN + 1) + 1; //即后面那段再加上10..0这一个1 

	/*[B]numOtherDigits是01346-21345除了第一位之外的数位中1的数目*/
	//后面剩下的4位数实际上还是能跑遍所有的4位数
	//而且最高位first是几,就能跑几遍.如作者给的这个例子就能完整跑完两遍
	//而且对于后面的四位数,无需考虑第一位非0的问题
	//因为前面有个最高位first在挂着
	//而每跑一趟1出现的次数,正是每一位是1,后面的任意组合
	//每一位是1一共length-1位,后面的任意组合即要乘以10^(length-2)
	//这样做是会遇到重复的数字,但每个数字在这个位上的1只计算一次
	//所以正好是题目要求的任意位出现1的总次数 
	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
	/*[C]numRecursive是1-1345中1的数目*/
	//这个过程即递归这个函数,传入除去最高位剩下的部分即可 
	int numRecursive = NumberOf1(strN + 1);
	//[A][B][C]三部分加起来即是所求 
	return numFirstDigit + numOtherDigits + numRecursive;
}

//求10的正整数n次方
int PowerBase10(unsigned int n) {
	int result = 1;
	for(unsigned int i = 0; i < n; ++ i)//直接连乘n个10 
		result *= 10;
	return result;
}

int main() {
	cout<<NumberOf1Between1AndN(21345)<<endl;//18821
	return 0;
}
