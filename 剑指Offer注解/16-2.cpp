#include<bits/stdc++.h>
using namespace std;

bool g_InvalidInput = false;//标识出错的全局变量,出错时设为true
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

// 参数:
//        base:      底数
//        exponent:  指数
// 返回值:
//        base的exponent次幂
double Power(double base, int exponent) {
	g_InvalidInput = false;
	//如果是0的负数次幂,因为0不能做分母,所以出错
	if (equal(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;//标记出错
		return 0.0;
	}

	//取指数的绝对值
	unsigned int absExponent = (unsigned int) (exponent);
	if (exponent < 0)
		absExponent = (unsigned int) (-exponent);
	//调用计算正指数次幂的方法
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)//指数本来是负的
		result = 1.0 / result;//那么要取个倒数
	return result;
}

// 参数:
//        base:      底数
//        exponent:  正指数
// 返回值:
//        base的exponent次幂
double PowerWithUnsignedExponent(double base, unsigned int exponent) {
	if (exponent == 0)
		return 1;//任何数的0次幂为1
	if (exponent == 1)
		return base;//任何数的1次幂为其本身

	//快速幂:递归调用自身计算指数的一半的次幂
	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;//再两个一半次幂乘起来就得到完整的了
	if ((exponent & 0x1) == 1)//如果最低位是1,即为奇数
		result *= base;//如7/2=3,3*3=6还差一份base,把它乘上
	return result;
}

//输入两个浮点数,只要它们的差值足够小即可判断为相等,返回是否相等 
bool equal(double num1, double num2) {
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

int main(){
	cout<<Power(2,3)<<endl;
	cout<<Power(-2,-3)<<endl;
	return 0;
}
