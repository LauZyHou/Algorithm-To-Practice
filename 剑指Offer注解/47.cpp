#include<bits/stdc++.h>
using namespace std;

//给出礼物矩阵的一维数组形式,行数,列数,求从矩阵中能获取的礼物的最大值
int getMaxValue_solution(const int* values, int rows, int cols) {
	if(values == nullptr || rows <= 0 || cols <= 0)//输入合法性检查
		return 0;

	//拦路数组:0~j-1=>f(i,0)~f(i,j-1);j~cols=>f(i-1,j)~f(i-1,cols-1)
	int* maxValues = new int[cols];
	for(int i = 0; i < rows; ++i) {//每一行
		for(int j = 0; j < cols; ++j) {//行内从左到右
			int left = 0;//左边的礼物价值
			int up = 0;//上边的礼物价值

			if(i > 0)//i>0时上边礼物存在
				up = maxValues[j];//f(i-1,j)存在mV[j]位置

			if(j > 0)//j>0时左边礼物存在
				left = maxValues[j - 1];//f(i,j-1)存在mV[j-1]位置

			//当前位置的礼物最大价值=左边和上边中大价值的一个+当前位置价值
			maxValues[j] = max(left, up) + values[i * cols + j];
		}
	}

	//最后跑完了整个矩阵,右下角位置的最大价值是该数组最右元素
	int maxValue = maxValues[cols - 1];

	delete[] maxValues;

	return maxValue;
}

int main() {
	int values[][4] = {
		{ 1, 10, 3, 8 },
		{ 12, 2, 9, 6 },
		{ 5, 7, 4, 11 },
		{ 3, 7, 16, 5 }
	};
	
	cout<<getMaxValue_solution((int *)(values),4,4)<<endl;

	return 0;
}
