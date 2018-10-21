#include<bits/stdc++.h>
using namespace std;

//寻找长度为length的升序数组numbers中某个和下标相等的元素
int GetNumberSameAsIndex(const int* numbers, int length) {
	if(numbers == nullptr || length <= 0)//输入合法性
		return -1;
	//二分左右点
	int left = 0;
	int right = length - 1;
	//查找
	while(left <= right) {
		//二分划分点,其实就是(right+left)>>2
		//我觉得下面作者这种写法的优势就是能避免上面的right+left越界
		int middle = left + ((right - left) >> 1);
		//中点和下标相等
		if(numbers[middle] == middle)
			return middle;//找到
		//中点值比下标大
		if(numbers[middle] > middle)
			right = middle - 1;//往左找
		else//比下标小
			left = middle + 1;//往右找
	}
	return -1;//没找到
}


int main() {
	int numbers[] = { -3, -1, 1, 3, 5 };
	cout<<GetNumberSameAsIndex(numbers,sizeof(numbers)/sizeof(int))<<endl;//3
	return 0;
}
