#include<bits/stdc++.h>
#include "../Utilities/Array.h"
using namespace std;

//输入长为n的input数组,将最小的k个数字写入长为k的output数组
void GetLeastNumbers_Solution1(int* input, int n, int* output, int k) {
	//非空校验,注意k是不能大于n的
	if(input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
		return;
	//先从头到尾随机划分一下
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	//当划分到的位置不是第k个位置(从0开始下标k-1)
	while(index != k - 1) {
		if(index > k - 1) {//如果大了
			//就在左边继续划分着找
			end = index - 1;
			index = Partition(input, n, start, end);
		} else {//如果小了
			//就在右边继续划分着找
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}
	//找完以后,最左边的k个数字就是最小的k个数字
	for(int i = 0; i < k; ++i)
		output[i] = input[i];
}

int main() {
	int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	int out[4];
	GetLeastNumbers_Solution1(data,8,out,4);
	for(int i=0;i<4;i++)
		cout<<out[i]<<"\t";
	return 0;
}
