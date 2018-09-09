#include<bits/stdc++.h>
using namespace std;

//输入绳子的长度,输出最大乘积 
int maxProductAfterCutting_solution1(int length) {
	if(length < 2)//因为要求长度n>1,所以这里返回0表示输入非法 
		return 0;
	if(length == 2)//长度为2时,因为要求剪下段数m>1,所以最大是1x1=1 
		return 1;
	if(length == 3)//长度为3时,因为要求剪下段数m>1,所以最大是1x2=2 
		return 2;
	
	//运行至此,说明绳子的长度是>3的,这之后0/1/2/3这种子问题最大就是其自身长度
	//而不再需要考虑剪一刀的问题,因为它们剪一刀没有不剪来的收益高
	//而在当下这么长的绳子上剪过才可能生成0/1/2/3这种长度的绳子,它们不需要再减
	//所以下面的表中可以看到它们作为子问题的值和上面实际返回的是不一样的 
	
	//在表中先打上子绳子的最大乘积 
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;//到3为止都是不剪最好 

	int max = 0;//用于记录最大乘积 
	//对于4以上的情况,每次循环要求f(i) 
	for(int i = 4; i <= length; ++i) {
		max = 0;//每次将最大乘积清空
		//因为要计算f(j)乘以f(i-j)的最大值,j超过i的一半时是重复计算
		//所以只需要考虑j不超过i的一半的情况 
		for(int j = 1; j <= i / 2; ++j) {
			//计算f(j)乘以f(i-j)
			int product = products[j] * products[i - j];
			//如果比当前找到的还大 
			if(max < product)
				max = product;//就把最大值更新 
		}
		//这里是循环无关的,书上在for里面,我把它提出来 
		products[i] = max;//最终,更新表中的f(i)=max(f(j)·f(i-j))
	}
	//循环结束后,所求的f(length)也就求出来了 
	max = products[length];//将其记录下来以在销毁后能返回 
	delete[] products;//销毁打表的辅助空间 
	return max; 
}

int main(){
	cout<<maxProductAfterCutting_solution1(9)<<endl;
	return 0;
}
