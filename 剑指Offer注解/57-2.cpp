#include<bits/stdc++.h>
using namespace std;

//输出从small到big的step为1的正整数序列
void PrintContinuousSequence(int small, int big) {
	for(int i = small; i <= big; ++ i)
		printf("%d ", i);
	printf("\n");
}

//寻找和为sum的全部正整数序列,将其输出 
void FindContinuousSequence(int sum) {
	if(sum < 3)//1+2尚且为3,小于3的没有 
		return;

	int small = 1;//序列头数字 
	int big = 2;//序列尾数字 
	int middle = (1 + sum) / 2;//终止条件:small不能超过这个值 
	int curSum = small + big;//保存当前的序列加和 

	while(small < middle) {//终止条件small=middle
		//当从"序列和太小了"->"序列和恰好"时,是由这个if来判定输出的 
		if(curSum == sum)//如果当前得到的序列和和要找的一样 
			PrintContinuousSequence(small, big);//输出序列 

		//如果序列和太大了 
		while(curSum > sum && small < middle) {
			//small向前走,同步更新当前序列和 
			curSum -= small;
			small ++;
			
			//当从"序列和太大了"->"序列和恰好"时,是由这个if来判定输出的
			//找到了,输出序列 
			if(curSum == sum)
				PrintContinuousSequence(small, big);
		}

		//至此,可能已经找到并输出了,也可能序列和太小了
		//不论是哪种情况,都应该让big往后走 

		big ++;
		curSum += big;//同步更新当前序列和 
	}
}

int main() {
	FindContinuousSequence(100);
	return 0;
}
