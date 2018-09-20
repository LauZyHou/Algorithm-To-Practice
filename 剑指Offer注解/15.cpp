#include<bits/stdc++.h>
using namespace std;

//能给面试官带来惊喜的解法 
int NumberOf1_Solution2(int n) {
	int count = 0;//计数 
	//循环直到数字中所有1全没了,就变成0结束 
	while (n) {
		++count;//记录这个1 
		n = (n - 1) & n;//去掉这个最右边的1 
	}
	return count;
}

int main() {
	cout<<NumberOf1_Solution2(11)<<endl;
	return 0;
}

//常规解法
int NumberOf1_Solution1(int n) {
	int count = 0;//计1的个数
	unsigned int flag = 1;//要测试某一位是否为1的测试值,初始测试最低位,所以用1
	//当左移没有超过二进制位数
	while (flag) {
		//用测试值和数字相与,可以测试相应的位
		if (n & flag)//相与为1,那一位为1
			count++;//记录之
		flag = flag << 1;//测试值左移
	}
	//循环的次数等于整数二进制的位数,左移超过了最高位就自然变0退出循环了
	return count;
}

//可能引起死循环的解法
int NumberOf1_Solution0(int n) {
	int count=0;//计数
	//只要n还不是0
	while(n) {
		if(n & 1)//如果n和1相与为1,即最低位为1
			count++;//记录一下
		n=n>>1;//右移一位把最低位挤掉
		//当是负数时,显然最左边会补1,这时候就停不下来了
	}
	return count;
}





