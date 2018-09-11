#include<bits/stdc++.h>
using namespace std;

/*本题的坐标图*/
//-------------X
//\
//\
//\
//\
//Y
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void printNumber(int number);


// 参数:
//        numbers:       矩阵(二维数组)的首地址
//        columns:       矩阵总的列数
//        rows:          矩阵总的行数
// 输出:
//        调用输出顺时针圈的函数,完成题意(顺时针打印矩阵)
void PrintMatrixClockwisely(int** numbers, int columns, int rows) {
	//输入合法性检查
	if(numbers == nullptr || columns <= 0 || rows <= 0)
		return;

	int start = 0;//最开始圈的起始点从左上角(0,0)开始

	//规律:当打印完毕时,起始点会超出行列长度至少其一的一半
	while(columns > start * 2 && rows > start * 2) {
		//输出这个顺时针圈
		PrintMatrixInCircle(numbers, columns, rows, start);
		//输出完了这圈,起始点向右下移动一步,成为新的顺时针圈起始点
		++start;
	}
}

// 参数:
//        numbers:       矩阵(二维数组)的首地址
//        columns:       矩阵总的列数
//        rows:          矩阵总的行数
//        start:         圈的起始处在左上角,相对坐标(start,start)
// 输出:
//        矩阵的一个顺时针圈
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
	//因为圈离边界的距离是确定的,以此计算圈右下角的相对坐标(endX,endY)
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	//从左到右打印一行,无论什么情况都要打印的
	for(int i = start; i <= endX; ++i) {//x坐标从起始到结尾
		int number = numbers[start][i];//即行数确定,列号在增
		printNumber(number);
	}

	//从上到下打印一列
	if(start < endY) {//只有当计算出的起始点在终止点上方时才需要打印
		for(int i = start + 1; i <= endY; ++i) {//y坐标从起始到结尾
			int number = numbers[i][endX];//即列数确定,行号在增
			printNumber(number);
		}
	}

	//从右到左打印一行
	if(start < endX && start < endY) {//这是最下面的一行,要求终止点确实在右下
		for(int i = endX - 1; i >= start; --i) {//x坐标从末尾到起始
			int number = numbers[endY][i];//即行数确定,列号在减
			printNumber(number);
		}
	}

	//从下到上打印一行
	if(start < endX && start < endY - 1) {//最后一步也要求在右下方,且高度至少差一个格子才需要上来
		for(int i = endY - 1; i >= start + 1; --i) {//y坐标从末尾到起始
			int number = numbers[i][start];//即列数确定,行号在减
			printNumber(number);
		}
	}
}

//格式化输出
void printNumber(int number) {
	printf("%d\t", number);
}


/*
1    2    3    4    5
6    7    8    9    10
11   12   13   14   15
16   17   18   19   20
21   22   23   24   25
*/
int main() {
	int rows=5,columns=5;
	//建立矩阵(二维数组)并初始化 
	int** numbers = new int*[rows]; 
	for(int i = 0; i < rows; ++i) {
		numbers[i] = new int[columns];
		for(int j = 0; j < columns; ++j) {
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	
	return 0;
}
