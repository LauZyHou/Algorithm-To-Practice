#include<bits/stdc++.h>
using namespace std;

//在长为length的numbers数组中找数对的最大差值 
int MaxDiff(const int* numbers, unsigned length) {
	//至少有2个数才能谈最大差值
	if(numbers == nullptr || length < 2)//更正:这里应是||而不是&&关系 
		return 0;

	int min = numbers[0];//min存遇到的最小数字,这里初始化为第一个数字
	
	//注意,不去记录最大数字,而是记录差值
	//要求的是差值最大,而最大数字也可能在最小数字的左边
	//同样地,这个差值完全可能和最小最大数字一个不占
	//但这里记录前面遇到的最小,是为了方便计算后面某个数结尾的最大差值 
	//而所求正是这些"某个数结尾的最大差值"中最大的一个 
	int maxDiff = numbers[1] - min;//存最大差值,初始化为前两个数差值 

	for(int i = 2; i < length; ++i) {//从2号数字开始一直到最后 
		//每次取它前一个数字和最小比较并更新,最后一个数没法作为买入点 
		if(numbers[i - 1] < min) 
			min = numbers[i - 1];//更新最小 

		int currentDiff = numbers[i] - min;//当前数字和前面的最小的差值 
		if(currentDiff > maxDiff)//如果发现更大差值 
			maxDiff = currentDiff;//更新差值 
	}
	//遍历完一趟数组后,就得到了最大差值 
	return maxDiff;
}

int main() {
	int numbers[] = { 4, 1, 3, 2, 5 };
	cout<<MaxDiff(numbers,sizeof(numbers)/sizeof(int))<<endl;//4
	return 0;
}
