#include<bits/stdc++.h>
using namespace std;

int g_maxValue = 6;//六面骰子 

void PrintProbability_Solution2(int number) {
	if(number < 1)//骰子至少有1个 
		return;

	int* pProbabilities[2];//两个数组
	//申请空间 
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	//全部初始化为0 
	for(int i = 0; i < g_maxValue * number + 1; ++i) {
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}
	
	//标识要操作的数组和辅助基准数组,它一改这两个数组的地位就交换了
	int flag = 0; 
	//一开始只有一个骰子,在0号数组中记录抽到1~6的频数都是1 
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;

	//接下来从2个骰子到number个骰子 
	for (int k = 2; k <= number; ++k) {
		//k个骰子最小出k,所以小于k的都设置为0 
		for(int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;
		//接下来从k到6k都是可能出现的 
		for (int i = k; i <= g_maxValue * k; ++i) {
			pProbabilities[1 - flag][i] = 0;//先清空为0
			//例如六面骰i=3,这次出现3=上次出现2和上次出现1的
			//例如六面骰i=50,这次出现50=上次出现49~44的
			//所以这里是要注意i比面数还小的时候其实是受制于i的 
			for(int j = 1; j <= i && j <= g_maxValue; ++j)//这里其实应该写j<i而不是j<=i,不过p[flag][0]是0也不影响 
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];//都加上来 
		}

		flag = 1 - flag;//标识反转,即下次循环中两个数组角色反转 
	}

	double total = pow((double)g_maxValue, number);//6面骰6^n种组合 
	for(int i = number; i <= g_maxValue * number; ++i) {//遍历所有可能数的频数 
		//计算概率,这里直接用flag因为最后一次for最后一句使flag已经反转了 
		double ratio = (double)pProbabilities[flag][i] / total; 
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

int main() {
	PrintProbability_Solution2(3);
	return 0;
}
