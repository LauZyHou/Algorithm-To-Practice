#include<bits/stdc++.h>
using namespace std;

// 参数:
//        data:        一个升序有序的整数数组
//        length:      数组的长度
//        k:           要寻找的数字 
//        start:       (子)数组起始位置下标 
//        end:         (子)数组结束位置下标 

//找到数组中第一个k的下标,如果数组中不存在k,返回-1
int GetFirstK(const int* data, int length, int k, int start, int end) {
	if(start > end)
		return -1;

	int middleIndex = (start + end) / 2;//二分查找,分割点 
	int middleData = data[middleIndex];//分割点处的值 

	if(middleData == k) {//分割点处值是k
		//分割点不是0,那么它前面一个数字如果不是k,它就是第一个k 
		//分割点是0即一定是第一个k 
		if((middleIndex > 0 && data[middleIndex - 1] != k)
		        || middleIndex == 0)
			return middleIndex;//找到了第一个k 
		else//它不是第一个k,第一个k一定在它左边 
			end  = middleIndex - 1;
	} else if(middleData > k)//分割点处值比k大 
		end = middleIndex - 1;//升序数组,k海如果存在一定在左边 
	else//分割点处比k小 
		start = middleIndex + 1;//升序数组,k海如果存在一定在右边 
	
	//运行至此说明还没找到第一个k,递归调用二分查找 
	return GetFirstK(data, length, k, start, end); 
}

//找到数组中最后一个k的下标,如果数组中不存在k,返回-1
//GetLastK和GetFirstK的思路一样 
int GetLastK(const int* data, int length, int k, int start, int end) {
	if(start > end)
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if(middleData == k) {//分割点处值是k
		//分割点不是length-1(最后一个点),那么它后面的点要不是k它就是最后一个
		//分割点是length-1,后面已经没了,它一定是最后一个k 
		if((middleIndex < length - 1 && data[middleIndex + 1] != k)
		        || middleIndex == length - 1)
			return middleIndex;
		else
			start  = middleIndex + 1;
	} else if(middleData < k)
		start = middleIndex + 1;
	else
		end = middleIndex - 1;

	return GetLastK(data, length, k, start, end);
}

//在长为length的排序data数组中计算k出现的次数 
int GetNumberOfK(const int* data, int length, int k) {
	int number = 0;//找不到就是0个 

	if(data != nullptr && length > 0) {//输入合法性检查 
		//找第一个k的下标和最后一个k的下标 
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		//大于-1即证实k的存在性,实际上这两个条件只要有一个满足另一个一定满足
		//因为只要"第一个k"存在,则"最后一个k"一定存在 
		if(first > -1 && last > -1)
			number = last - first + 1;//两个k之间全是k,因为数组是排序数组 
	}

	return number;
}

int main() {
	int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
	cout<<GetNumberOfK(data,sizeof(data)/sizeof(int),3)<<endl;//4
	return 0;
}
