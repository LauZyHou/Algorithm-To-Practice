#include<bits/stdc++.h>
using namespace std;

//判断数字num的第indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit) {
	num = num >> indexBit;//indexBit从0开始计数,右移indexBit使其变成最低位
	return (num & 1);//和最低位1相与即可
}

//找到num从右边数起第一个是1的位
unsigned int FindFirstBitIs1(int num) {
	int indexBit = 0;//计数(接下来要检查的位)
	//当前最低位是0,且要检查的位数没有超过极限位数8x字节数
	while(((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
		num = num >> 1;//右移1位使下一位成为最低位
		++indexBit;//下次循环要检查的位
	}
	return indexBit;//将这个位数返回,如果没找到那就是8*sizeof(int)
}

//在二复制数组中找两个只出现一次的数字,存入后两个参数指示的内存空间
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
	if(data == nullptr || length < 2)//输入合法性检查,最少应该2个数字
		return;

	int resultExclusiveOR = 0;//存总的异或结果,注意初始化是0才在和第一个异或时使其不变
	for(int i = 0; i < length; ++i)
		resultExclusiveOR ^= data[i];//挨个做^异或运算

	//在结果中找最低的是1的那一位,返回从0开始计数的位数
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = *num2 = 0;//两个数字将按照刚刚找到的那一位异或出来
	for(int j = 0; j < length; ++j) {//再次遍历数组中的每个数
		if(IsBit1(data[j], indexOf1))//如果这个数的那一位是1
			*num1 ^= data[j];//就将这个数异或到第一个变量上
		else//反之,在逻辑上属于另一个子数组
			*num2 ^= data[j];//异或到另一个变量上
	}
}

int main() {
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int n1,n2;
	FindNumsAppearOnce(data,sizeof(data)/sizeof(int),&n1,&n2);
	cout<<n1<<","<<n2<<endl;//6,4
	return 0;
}
