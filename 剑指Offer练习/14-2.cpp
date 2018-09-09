#include<bits/stdc++.h>
using namespace std;

//输入绳子的长度,输出最大乘积 
int maxProductAfterCutting_solution2(int length) {
	if(length < 2)//因为要求长度n>1,所以这里返回0表示输入非法 
		return 0;
	if(length == 2)//长度为2时,因为要求剪下段数m>1,所以最大是1x1=1 
		return 1;
	if(length == 3)//长度为3时,因为要求剪下段数m>1,所以最大是1x2=2 
		return 2;

	//尽可能多地减去长度为3的绳子段,这里是计算一下能减出多少个3 
	int timesOf3 = length / 3;

	//当绳子最后剩下的长度为4的时候,不能再剪去长度为3的绳子段。
	//此时更好的方法是把绳子剪成长度为2的两段,因为2*2>3*1。
	if(length - timesOf3 * 3 == 1)//如果最后只剩一个1 
		timesOf3 -= 1;//就要留下一个3 

	//保证剩下的一定是4或者2或者0,计算一下能剪出几个2来(只有2/1/0三种情况) 
	int timesOf2 = (length - timesOf3 * 3) / 2;
	
	//3的多少个3次幂,再乘以2的多少个2次幂,就是贪心选择的最优解 
	return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));
}

int main(){
	cout<<maxProductAfterCutting_solution2(9)<<endl;
	return 0;
}
