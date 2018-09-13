#include<bits/stdc++.h>
using namespace std;

int compare(const void* strNumber1, const void* strNumber2);

//int型整数用十进制表示最多只有10位
const int g_MaxNumberLength = 10;

//存[m][n]的字符串 
char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
//存[n][m]的字符串 
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

//给出整形数组和数组长度,输出排成的最小的数 
void PrintMinNumber(const int* numbers, int length) {
	if(numbers == nullptr || length <= 0)//数组非空校验 
		return;

	//存储若干char数组,所需空间和输入的整形数组一样 
	char** strNumbers = (char**)(new int[length]);
	//对于这length个数 
	for(int i = 0; i < length; ++i) {
		//每个数分配一个char类型数组存储,+1是为了存'\0' 
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		//将输入的对应位置的整数写入相应的字符串中 
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	//对strNumbers中的元素(是char数组)进行排序
	//传入自定义的compare函数指针以确定排序的方法 
	qsort(strNumbers, length, sizeof(char*), compare);

	//排好序后,按顺序将其输出即可 
	for(int i = 0; i < length; ++i)
		printf("%s", strNumbers[i]);
	printf("\n");

	//释放堆空间 
	for(int i = 0; i < length; ++i)
		delete[] strNumbers[i];
	delete[] strNumbers;
}

//如果[strNumber1][strNumber2] > [strNumber2][strNumber1],返回值大于0
//如果[strNumber1][strNumber2] = [strNumber2][strNumber1],返回值等于0
//如果[strNumber1][strNumber2] < [strNumber2][strNumber1],返回值小于0
int compare(const void* strNumber1, const void* strNumber2) {
	//[strNumber1][strNumber2]就是先拷贝1再连接2 
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	//[strNumber2][strNumber1]就是先拷贝2再连接1
	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);
	
	//直接调用字符串比较的函数 
	return strcmp(g_StrCombine1, g_StrCombine2);
}

int main(){
	int numbers[]={3,32,321};
	PrintMinNumber(numbers,sizeof(numbers)/sizeof(int));
	return 0;
}

