#include<bits/stdc++.h>
using namespace std;

//比较两个指针内容的大小 
int Compare(const void *arg1, const void *arg2) {
	//比较将其转成int指针后取内容的大小 
	return *(int*) arg1 - *(int*) arg2;
}

//输入长为length的numbers数组表示的扑克牌,判断是不是顺子 
bool IsContinuous(int* numbers, int length) {
	if(numbers == nullptr || length < 1)//输入合法性 
		return false;
	
	//扑克牌最多就那些牌,排序时间复杂度是O(1)的而不再是O(nlogn) 
	qsort(numbers, length, sizeof(int), Compare);

	int numberOfZero = 0;//大小王的数目 
	int numberOfGap = 0;//空缺数目 

	//统计数组中0的个数
	for(int i = 0; i < length && numbers[i] == 0; ++i)
		++numberOfZero;

	//统计数组中的间隔数目
	int small = numberOfZero;//初始化为第一个数地址 
	int big = small + 1;//初始化为相邻的第二个数地址 
	while(big < length) {//big=length时统计的是最后一对 
		//两个数相等,有对子,不可能是顺子
		if(numbers[small] == numbers[big])
			return false;
		//空缺数+=相邻两数的数字差-1,例如(1,4)之间少了两数(2,3) 
		numberOfGap += numbers[big] - numbers[small] - 1;
		//向前走一步,下一对 
		small = big;
		++big;
	}
	//至此,说明没有对子
	//如果空缺总数不超过0的总数就能被填满,是顺子 
	return (numberOfGap > numberOfZero) ? false : true;
}

int main() {
	int numbers[] = { 1, 3, 0, 5, 0 };
	cout<<boolalpha<<IsContinuous(numbers,sizeof(numbers)/sizeof(int))<<endl;//true 
	return 0;
}
