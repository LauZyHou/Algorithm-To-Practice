#include<bits/stdc++.h>
using namespace std;

// 参数:
//        numbers:     要查找的数组首地址
//        index1:      查找的起始游标
//        index2:      查找的结束游标
// 返回值:
//        找到的最小数字
int MinInOrder(int* numbers, int index1, int index2) {
	int result = numbers[index1];//从起始游标处开始
	//遍历整个游标范围
	for(int i = index1 + 1; i <= index2; ++i) {
		//如果发现比当前result更小的数
		if(result > numbers[i])
			result = numbers[i];//记录之
	}
	return result;//最终找到的就是最小的 
}


// 参数:
//        numbers:     旋转后的数组首地址
//        length:      数组的长度
// 返回值:
//        找到的最小数字
int Min(int* numbers, int length) {
	//输入合法性校验
	if(numbers == nullptr || length <= 0)
		throw new exception();

	int index1 = 0;//初始化游标P1
	int index2 = length - 1;//初始化游标P2
	int indexMid = index1;//indexMid最终将指向数组中最小的数,初始化为一个数
	//这样在这个循环前判断,如果发现数组中第一个数小于最后一个数,就可以直接返回第一个数
	while(numbers[index1] >= numbers[index2]) {
		//[找到最小数的条件]
		//如果index1和index2指向相邻的两个数
		//则index1指向第一个递增子数组的最后一个数字
		//index2指向第二个子数组的第一个数字,也就是数组中的最小数字
		if(index2 - index1 == 1) {
			indexMid = index2;//记录下index2为所求
			break;
		}

		//如果下标为index1、index2和indexMid指向的三个数字相等
		//则只能顺序查找,因为无法判断该走向哪一边
		//但能确定一定还在[index1,inedx2]这个游标区间内
		indexMid = (index1 + index2) / 2;
		if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);//返回顺序查找的结果

		//缩小查找范围
		//如果中间数不小于P1数,说明分界点在后面
		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;//所以将P1后移
		//如果中间数不小于P2数,说明分界点在前面面
		else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;//所以将P2前移
	}
	return numbers[indexMid];//最终,中间数点就是分界点,即为所求
}

int main(){
	int array[] = { 3, 4, 5, 1, 2 };
	try{
		cout<<Min(array,5)<<endl;
	}catch(...){
		cerr<<"Invalid parameters"<<endl;
	}
	return 0;
}

