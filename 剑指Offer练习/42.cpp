#include<bits/stdc++.h>
using namespace std;

bool g_InvalidInput = false;//指示是否出错的全局变量 

//传入数组和数组长度,返回连续子数组的最大和 
int FindGreatestSumOfSubArray(int *pData, int nLength) {
	//输入合法性检查 
	if((pData == nullptr) || (nLength <= 0)) {
		g_InvalidInput = true;
		return 0;
	}
	
	//这句没意义,这里还是保留作者的写法 
	g_InvalidInput = false;

	int nCurSum = 0;//累加的子数组和 
	//最小int数,即-(2^31),该变量记录运行至此捕获的最大和 
	int nGreatestSum = 0x80000000;
	//遍历数组中的每个元素 
	for(int i = 0; i < nLength; ++i) {
		if(nCurSum <= 0)//如果之前累加的和是非正的 
			nCurSum = pData[i];//那抛弃之前的,用这次遇到的数开始累加 
		else//如果之前累加的和是正的,那还可能对后续有积极作用 
			nCurSum += pData[i];//那把这次的和加上来 

		if(nCurSum > nGreatestSum)//如果找到了更大的和 
			nGreatestSum = nCurSum;//替换掉 
	}

	return nGreatestSum;
}


int main() {
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	cout<<FindGreatestSumOfSubArray(data,sizeof(data)/sizeof(int));
	return 0;
}
