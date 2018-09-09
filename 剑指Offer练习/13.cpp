#include<bits/stdc++.h>
using namespace std;

/*声明部分*/
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

// 参数:
//        threshold:      阈值,即题目中的k值
//        rows:           矩阵的行数
//        cols:           矩阵的列数
// 返回值:
//        题目要求的结果,即机器人可达的格子数目
int movingCount(int threshold, int rows, int cols) {
	//输入合法性检查
	if(threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	//创建访问情况矩阵,全部初始化为false
	bool *visited = new bool[rows * cols];
	for(int i = 0; i < rows * cols; ++i)
		visited[i] = false;
	//从左上角(0,0)点开始,调用这个搜寻可达点的函数计算出可达点数目
	int count = movingCountCore(threshold, rows, cols,
	                            0, 0, visited);
	delete[] visited;//释放辅助空间(访问情况矩阵)
	return count;
}

// 参数:
//        threshold:      阈值,即题目中的k值
//        rows:           矩阵的行数
//        cols:           矩阵的列数
//        row:            当前行
//        col:            当前列
//        visited:        访问情况矩阵
// 返回值:
//        从该点开始(有访问情况矩阵限制不重复),新发现的可达点数目
int movingCountCore(int threshold, int rows, int cols, int row,
                    int col, bool* visited) {
	int count = 0;//计数(新发现的可达点数目),从0开始
	//检查当前点是可以进入的
	if(check(threshold, rows, cols, row, col, visited)) {
		visited[row * cols + col] = true;//将该点标记为已被访问
		//因为该点可以进入,所以计数要算上这个点,从1开始加
		//递归调用,加上上/左/下/右四个方向发现的可达点数目
		count = 1 + movingCountCore(threshold, rows, cols,
		                            row - 1, col, visited)
		        + movingCountCore(threshold, rows, cols,
		                          row, col - 1, visited)
		        + movingCountCore(threshold, rows, cols,
		                          row + 1, col, visited)
		        + movingCountCore(threshold, rows, cols,
		                          row, col + 1, visited);
	}
	//如果不能进入,自然返回0
	return count;//返回计数
}

// 参数:
//        threshold:      阈值,即题目中的k值
//        rows:           矩阵的行数
//        cols:           矩阵的列数
//        row:            当前行
//        col:            当前列
//        visited:        访问情况矩阵
// 返回值:
//        true表示能进入该方格,false表示不能
bool check(int threshold, int rows, int cols, int row, int col,
           bool* visited) {
	//行列坐标合法,且行列的位和之和不超过阈值,且该位置未访问过
	if(row >= 0 && row < rows && col >= 0 && col < cols
	        && getDigitSum(row) + getDigitSum(col) <= threshold
	        && !visited[row* cols + col])
		return true;//满足这些条件,就能进入这个方格
	return false;//否则不能进入
}

//输入正整数number,输出其各个数位之和
int getDigitSum(int number) {
	int sum = 0;
	while(number > 0) {
		sum += number % 10;//把最低位取出来加到总和里
		number /= 10;//去除最低位
	}
	return sum;
}

int main() {
	cout<<movingCount(15,20,20)<<endl;
	return 0;
}
