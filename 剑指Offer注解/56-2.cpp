#include<bits/stdc++.h>
using namespace std;

//在三复制数组中找只出现一次的一个数字 
int FindNumberAppearingOnce(int numbers[], int length) {
	if(numbers == nullptr || length <= 0)//输入合法性 
		throw new exception();

	int bitSum[32] = {0};//4字节32位int,存32整个数组按位加之后每一位的情况 
	
	//注意,这里按作者的写法是反过来存的,有点绕
	//如bit[31]其实是最低bit位的的值相加的结果
	//这从内存的角度看也可以理解...
	//总之数组下标高的存的是整数的低位加和 
	
	for(int i = 0; i < length; ++i) {//遍历整个数组 
		int bitMask = 1;//比特掩码,用于取int数特定位置的bit值 
		for(int j = 31; j >= 0; --j) {
			int bit = numbers[i] & bitMask;//取这一位的值 
			if(bit != 0)//如果是1 
				bitSum[j] += 1;//将数组中对应位置+1 
			bitMask = bitMask << 1;//掩码左移一位,下次循环要取那一位的值 
		}
	}

	int result = 0;//最终结果,先将所有位置置0 
	for(int i = 0; i < 32; ++i) {//从高位向低位看 
		result = result << 1;//左移,之后最低位是要考察和设置的位 
		result += bitSum[i] % 3;//如果是3的倍数就+0,否则+1 
	}

	return result;
}

int main() {
	int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
	cout<<FindNumberAppearingOnce(numbers,sizeof(numbers)/sizeof(int))<<endl;//1023
	return 0;
}
