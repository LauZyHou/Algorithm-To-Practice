#include<bits/stdc++.h>
using namespace std;

//不用四则运算做加法 
int Add(int num1, int num2) {
	int sum, carry;//分别表示:不考虑进位的加和,进位 
	do {
		sum = num1 ^ num2;//由前面分析直接用二进制异或 
		carry = (num1 & num2) << 1;//与运算后再左移一位 
		
		//分别存到num1和num2上,因为下次循环做的就是sum和carry的相加 
		num1 = sum;
		num2 = carry;
	} while(num2 != 0);//直到num2也就是carry进位是0为止 

	return num1;//这时结果已经计算好,在num1即sum里了 
}

int main() {
	cout<<Add(130,1888)<<endl;//2018
	return 0;
}
