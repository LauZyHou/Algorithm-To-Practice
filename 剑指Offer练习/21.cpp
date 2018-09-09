#include<bits/stdc++.h>
using namespace std;

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

//输入要做操作的数组,数组的长度
void ReorderOddEven_2(int *pData, unsigned int length) {
	Reorder(pData, length, isEven);//在这里传入要用于判断的函数
	//当条件改变时,只要再写一个函数,然后在这里改变传进去的函数即可 
}

//输入要做操作的数组,数组的长度,用于判断的函数指针(一个int参数,返回值是bool) 
void Reorder(int *pData, unsigned int length, bool (*func)(int)) {
	//输入非空校验 
	if(pData == nullptr || length == 0)
		return;

	int *pBegin = pData;//左侧指针从第一个元素开始
	int *pEnd = pData + length - 1;//右侧指针从最后一个元素开始

	//只要两指针尚未相遇
	while(pBegin < pEnd) {
		//向右移动pBegin,直到函数对其计算为false 
		while(pBegin < pEnd && !func(*pBegin))
			pBegin ++;

		//向左移动pEnd,直到函数对其计算为true
		while(pBegin < pEnd && func(*pEnd))
			pEnd --;

		//再次检查它们没有相遇过
		if(pBegin < pEnd) {
			//交换它们所指向的两个元素的值
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//解耦出的判断奇偶的函数 
bool isEven(int n) {
	//和1相与为0即为偶数,该函数当输入偶数时返回true
	return (n & 1) == 0;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    int length=sizeof(numbers)/sizeof(int);
    ReorderOddEven_2(numbers,length);
    for(int i=0;i<length;i++)
        cout<<numbers[i]<<"\t";
    return 0;
}
