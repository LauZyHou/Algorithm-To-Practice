#include<bits/stdc++.h>
#include "../Utilities/Array.h"
using namespace std;

//全局变量,用于指示是否出错
bool g_bInputInvalid = false;

//检查数组是否合法
bool CheckInvalidArray(int* numbers, int length) {
	g_bInputInvalid = false;
	if(numbers == nullptr && length <= 0)//数组不合法时
		g_bInputInvalid = true;//同样在这个全局变量上做出指示

	return g_bInputInvalid;
}

//确认number在长为length的numbers数组中是否超过一半
bool CheckMoreThanHalf(int* numbers, int length, int number) {
	//统计number在数组中出现的次数
	int times = 0;
	for(int i = 0; i < length; ++i) {
		if(numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	//如果没有超过一半
	if(times * 2 <= length) {
		g_bInputInvalid = true;//在全局变量上做出指示
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

//把上面两部分单独写到一个函数里可以和方法解耦,多个方法不用重复代码 

//====================方法1====================
int MoreThanHalfNum_Solution1(int* numbers, int length) {
	if(CheckInvalidArray(numbers, length))
		return 0;
	//长度的一半,数组中位数出现的位置 
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	//随机划分一下,返回划分后的坐标位置 
	int index = Partition(numbers, length, start, end);
	cout<<"划分位置是"<<index<<",值是"<<numbers[index]<<endl;
	//只要划分后不在中位数位置,就一直循环
	//注意:这个Partition每次划分将>=它的都放在右边
	//所以右边的数往往会很多,特别是在这个题的这种大量一样数字的输入情况下 
	//并且在后续的递归中,这种情况也完全不会变好
	//不妨输出一下每次划分的位置看一下这种有点蠢的查找方式，， 
	while(index != middle) {
		if(index > middle) {//如果比中位数大 
			end = index - 1;//就继续在左边找 
			index = Partition(numbers, length, start, end);
			cout<<"划分位置是"<<index<<",值是"<<numbers[index]<<endl;
		} else {//如果比中位数小 
			start = index + 1;//就继续在右边找 
			index = Partition(numbers, length, start, end);
			cout<<"划分位置是"<<index<<",值是"<<numbers[index]<<endl;
		}
	}

	int result = numbers[middle];//最终结果就是划分在中间位置时(中位数)
	//最后要检查一下是不是确实超过一半,花O(n)时间不增加总时间复杂度 
	if(!CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
}

int main() {
	int numbers[]={1,2,3,2,2,2,2,2,2,2,2,2,5,4,2};
	MoreThanHalfNum_Solution1(numbers,15);
	return 0;
}
