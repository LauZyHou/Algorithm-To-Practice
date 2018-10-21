#include<bits/stdc++.h>
using namespace std;

//数组长为length的升序数字数组numbers,返回缺失的数字
//这里应该注意length就是题目中的n-1
//因为n个数字缺了1个只剩n-1个,实际读入就读了n-1个而不是读了n个 
int GetMissingNumber(const int* numbers, int length) {
	//输入合法性检查 
	if(numbers == nullptr || length <= 0)
		return -1;

	int left = 0;//二分查找左位置 
	int right = length - 1;//二分查找右位置 
	while(left <= right) {//没找到时左>右 
		int middle = (right + left) >> 1;//二分中点 
		if(numbers[middle] != middle) {//如果和下标不同
			//下标是0,就缺0
			//下标不是0,看左边一个数是不是和它的下标相等 
			if(middle == 0 || numbers[middle - 1] == middle - 1)
				return middle;//如果是,当前下标就是缺的那个数 
			right = middle - 1;//否则,往左找 
		} else//中点和下标相同 
			left = middle + 1;//往右找 
	}

	//特别注意,当缺的那个数就是n-1的时候,上面的循环找不到
	//一直往右找,最后找到left=length超过right=length-1结束循环 
	if(left == length)
		//特别注意length就是n-1,length-1可就是n-2了 
		return length; 

	//无效的输入,比如数组不是按要求排序的
	//或者有数字不在0到n-1范围之内
	return -1;
}


int main() {
	int numbers[]={0,1,2,3,5,6,7};
	cout<<GetMissingNumber(numbers,7)<<endl;//4
	return 0;
}
