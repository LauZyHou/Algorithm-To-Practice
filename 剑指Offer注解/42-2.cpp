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
	
	int f_i=0;//既是上次循环的f[i-1],也是这次循环的f[i]
	//f[i]的意思是以第i个数字结尾的子数组的最大和 
	
	int max_f_i=0x80000000;//最大的f[i]就是所求,不一定在哪结束 
	
	for(int i=0;i<nLength;i++){
		if(f_i<=0)//如果f[i-1]是负的,不能为f[i]做出贡献
			f_i=pData[i];//当前f[i]就从当前位置开始当前位置结束就是最大的 
		else//如果是正的,那么f[i]肯定要连接它的
			f_i=f_i+pData[i];//把它和当前这个结点连接起来就是f[i] 
		if(f_i>max_f_i)//如果找到了更大的f[i]
			max_f_i=f_i;
	}

	return max_f_i;//最大的f[i]就是所求 
}

int main() {
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	cout<<FindGreatestSumOfSubArray(data,sizeof(data)/sizeof(int));
	return 0;
}
