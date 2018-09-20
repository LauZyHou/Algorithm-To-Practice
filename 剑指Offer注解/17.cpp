#include<bits/stdc++.h>
using namespace std;

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================方法一====================
void Print1ToMaxOfNDigits_1(int n) {
	if (n <= 0)//位数不能非正
		return;
	//初始化n位数空间
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	//当还没超出最大的n位数,不断增加1 
	while (!Increment(number)) {
		PrintNumber(number);//调用输出的函数 
	}
	//清除存n位数的空间 
	delete[]number;
}

//number为字符数组表示的大数,在其上自增1,溢出时返回true
bool Increment(char* number) {
	bool isOverflow = false;//是否溢出 
	int nTakeOver = 0;//当前这一位要加上的,来自上一位的进位数 
	int nLength = strlen(number);//字符数组的长度,即数字有多少位 
	//从低位(后)向高位(前)遍历 
	for (int i = nLength - 1; i >= 0; i--) {
		//当前这一位的新值=旧值+进位数 
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)//如果是最低位 
			nSum++;//需要把这个值加1,因为整体的操作就是整个数+1 
		//如果已经超过10了(实际上这里最多就是10),即发生了进位 
		if (nSum >= 10) {
			if (i == 0)//如果是在最高位上发生的 
				isOverflow = true;//说明已经溢出了,标记一下 
				//已经到最高位了,不break也会结束循环 
			else {//否则,需要做进位处理 
				nSum -= 10;//本位只留个零头(其实就是本位变成0) 
				nTakeOver = 1;//进位值设置成1 
				number[i] = '0' + nSum;//设置当前位的新值,并继续循环,因为高位也可能进位 
			}
		} else {//如果不存在进位 
			number[i] = '0' + nSum;//设置当前位的新值 
			break;//不需要在循环了,因为高位也不可能再进位了 
		}
	}
	return isOverflow;
}

// ====================方法二====================
void Print1ToMaxOfNDigits_2(int n) {
	if (n <= 0)//位数不能非正
		return;
	//初始化n位数空间,不需要清0,因为将使用全排列来实现 
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; ++i) {
		number[0] = i + '0';//最高位从0到9设置一遍 
		Print1ToMaxOfNDigitsRecursively(number, n, 0);//递归地调用全排列的函数输出 
	}
	//清除存n位数的空间 
	delete[] number;
}

//number为字符数组表示的大数,length为数的有效位数,index为当前已设置的位号 
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
	if (index == length - 1) {//如果已经设置到了最后一位 
		PrintNumber(number);//直接调用输出函数即可 
		return;//这时是递归出口 
	}
	//否则,既然没有设置到最后一位,就要对下一位调用该函数做全排列 
	for (int i = 0; i < 10; ++i) {
		number[index + 1] = i + '0';//将下一位从0到9设置一遍 
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);//递归调用 
	}
}

// ====================公共函数====================
//字符串number表示一个数字，数字有若干个0开头
//打印出这个数字，并忽略开头的0
void PrintNumber(char* number) {
	bool isBeginning0 = true;//记录是否还处在首部的若干0中,默认是 
	int nLength = strlen(number);//字符串长度
	//从高位向低位的每一位 
	for (int i = 0; i < nLength; ++i) {
		//如果还在若干个0中,且第一次遇到了非0数 
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;//那么要把这个标识置为false,表示已经走出了0海 
		//只要不是在0海中 
		if (!isBeginning0) {
			printf("%c", number[i]);//不管是什么数字都要输出,0海之后是可以有0的 
		}
	}
	printf("\t");
}

int main(){
	Print1ToMaxOfNDigits_1(2);
	Print1ToMaxOfNDigits_2(2);
	return 0;
}
