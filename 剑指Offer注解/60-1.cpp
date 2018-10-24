#include<bits/stdc++.h>
using namespace std;

int g_maxValue = 6;//六面骰子 

//递归函数:递归调用每次拿出一个骰子,六个分支,更新频数数组 
// 参数:
//        original:       骰子总数 
//        current:        当前未计算的骰子数 
//        sum:            前面层已经计算得的骰子数总和
//        pProbabilities: 要更新的频数数组 
void Probability(int original, int current, int sum,
                 int* pProbabilities) {
	if(current == 0) {//递归出口:如果骰子已经都计算过 
		pProbabilities[sum - original]++;//更新频数数组,即对应位置处+1 
	} else {//如果还剩多个骰子 
		for(int i = 1; i <= g_maxValue; ++i) {//再拿出一个骰子,对其的每种取值
			//递归调用以更新频数数组,每个分支中当前骰子数减去这个骰子
			//点数总数是局部自动变量,各自更新为当前点数+之前计算的点数和 
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

//递归外套
//计算number个骰子朝上点数和的所有可能值出现的概率,保存在pProbabilities数组中
void Probability(int number, int* pProbabilities) {
	for(int i = 1; i <= g_maxValue; ++i)//对第一个骰子的g_maxValue种取值 
		Probability(number, number-1, i, pProbabilities);//分别调用递归函数去更新频数数组 
}

//打印number个骰子朝上点数和的所有可能值出现的概率 
void PrintProbability_Solution1(int number) {
	if(number < 1)//至少1个骰子 
		return;

	int maxSum = number * g_maxValue;//可能出现的最大点数 
	int* pProbabilities = new int[maxSum - number + 1];//点数从number~maxSum,所以数组长n-m+1 
	for(int i = number; i <= maxSum; ++i)
		pProbabilities[i - number] = 0;//总点数为i的频数会保存在i-number里 

	//计算number个骰子朝上点数和的所有可能值出现的概率,保存在pProbabilities数组中 
	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);//n个骰子的所有点数的排列数为g_maxValue的n次方 
	for(int i = number; i <= maxSum; ++i) {//对每个可能的点数 
		double ratio = (double)pProbabilities[i - number] / total;//计算概率=频数/总数 
		printf("%d: %e\n", i, ratio);//打印 
	}
	delete[] pProbabilities;//销毁堆空间的频数数组 
}

int main() {
	PrintProbability_Solution1(3);
	return 0;
}
