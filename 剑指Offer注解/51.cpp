#include<bits/stdc++.h>
using namespace std;

// 参数:
//        data:        一个整数数组
//        copy:        复制数组
//        start:       操作起点下标
//        end:         操作终点下标
// 返回值:
//        data数组中从start到end位置逆序对的总数
int InversePairsCore(int* data, int* copy, int start, int end) {
	if(start == end) {//递归出口:子数组中仅有一个数字
		copy[start] = data[start];//将其直接拷贝到copy数组
		return 0;//只有一个数字,一定不包含逆序对
	}

	int length = (end - start) / 2;//二分数组,子数组的长度

	//左侧部分/右侧部分分别递归计算:反过来调用则最终有序的在data数组里
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	//i初始化为前半段最后一个数字的下标(前半段最大数)
	int i = start + length;
	//j初始化为后半段最后一个数字的下标(后半段最大数)
	int j = end;
	int indexCopy = end;//要复制到的copy数组的位置下标
	int count = 0;//比较过程中发现的逆序对数目
	//两个子数组中都有数字未复制完
	while(i >= start && j >= start + length + 1) {
		if(data[i] > data[j]) {//左侧数组中的数更大
			copy[indexCopy--] = data[i--];//复制到copy数组中
			//右侧子数组中剩余的所有数字都和左侧数组中的这个数字构成逆序对
			count += j - start - length;//注意start+length才是分割点的位置下标
		} else {//右侧数组中的数更大
			copy[indexCopy--] = data[j--];
		}
	}

	//上面的&&条件有一边不满足就终止,这时左右有一个数组还没复制完

	for(; i >= start; --i)//左侧数组剩余复制完
		copy[indexCopy--] = data[i];

	for(; j >= start + length + 1; --j)//右侧数组剩余复制完
		copy[indexCopy--] = data[j];

	//左侧逆序对数+右侧逆序对数+本批计算得逆序对数
	return left + right + count;
}

// 参数:
//        data:        一个整数数组
//        length:      数组的长度
// 返回值:
//        data数组中逆序对的总数
int InversePairs(int* data, int length) {
	//空数组或者长度不合法,这里应用<=0而不是<0
	if(data == nullptr || length <= 0)
		return 0;

	//深拷贝data数组到copy数组中
	int* copy = new int[length];
	for(int i = 0; i < length; ++i)
		copy[i] = data[i];

	//调用统计逆序对数目的递归函数
	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

int main() {
	int data[] = { 1, 2, 3, 4, 7, 6, 5 };
	cout<<InversePairs(data,7)<<endl;//3
	return 0;
}
