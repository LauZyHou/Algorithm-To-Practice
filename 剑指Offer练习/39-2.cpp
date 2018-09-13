#include<bits/stdc++.h>
using namespace std;

//====================方法2====================
int MoreThanHalfNum_Solution2(int* numbers, int length) {
	if(CheckInvalidArray(numbers, length))//检查数组合法性 
		return 0;

	int result = numbers[0];//擂主一开始是第一个数字 
	int times = 1;//分数是1
	//遍历剩下的所有挑战者 
	for(int i = 1; i < length; ++i) {
		if(times == 0) {//如果分数掉到0了
			result = numbers[i];//有新的挑战者上台直接当擂主
			times = 1;//刚上台分数肯定是1 
		} else if(numbers[i] == result)//如果和擂主同族(数字一样) 
			times++;//分数+1,相当于给擂主加HP 
		else//如果不同族(数字不一样) 
			times--;//掉一分,相当于擂主花1HP打掉1HP的挑战者 
	}

	//最终检查一下找到的数字是不是确实超过一半 
	if(!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}

int main() {



	return 0;
}
