#include<bits/stdc++.h>
using namespace std;

int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

//输入位数index,在数字序列中找出第index数字并返回 
int digitAtIndex(int index) {
	if(index < 0)//输入合法性检查 
		return -1;

	int digits = 1;//当前这一族数的位数,开始是1位数 
	while(true) {
		int numbers = countOfIntegers(digits);//计算digits位的数有多少个 
		if(index < numbers * digits)//如果剩下的index不超过这族数字海
			//那么就是digits位一族的数字海向后走index位
			return digitAtIndex(index, digits);//调用函数寻找并返回 
		//运行至此,没有走if,说明已经走出了这族数字海 
		index -= digits * numbers;//所剩index=原index-这族数字海的数字数目 
		digits++;//下轮检查的位数+1
	}
	//程序无法运行到这里,但为了满足int返回值 
	return -1;
}

//计算digits位一族的数字海中有多少数字 
int countOfIntegers(int digits) {
	if(digits == 1)//一位数有10个 
		return 10;
	//两位数有99-10+1=90个;三位数有999-100+1=900个;四位数有9000个... 
	int count = (int) pow(10, digits - 1);
	return 9 * count;//即9*10^(digits-1)个数字 
}

//计算返回digits位一族的数字海向后走index位
int digitAtIndex(int index, int digits) {
	//先从起始数字开始,向后走index/digits个真实的数字
	int number = beginNumber(digits) + index / digits;
	//然后面对的这个数就包含了要找的位 
	//计算一下它在这个数上是从右往左的第几位
	//即每个数的位数,减去index的余数 
	int indexFromRight = digits - index % digits;
	//将这个数取出来,先把它后面的数用自除去掉 
	for(int i = 1; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;//然后这个个位就是所求了 
}

//计算digits位数字海的第一个数(不是第一位数) 
int beginNumber(int digits) {
	if(digits == 1)//1位数字海第一个数是0 
		return 0;
	//2位是10,3位是100,4位是1000... 
	return (int) pow(10, digits - 1);
}

int main(){
	cout<<digitAtIndex(1001)<<endl;
	return 0;
}
