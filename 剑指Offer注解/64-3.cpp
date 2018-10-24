#include<bits/stdc++.h>
using namespace std;

//定义函数指针类型,类型名称为fun,该类型所定义的变量将是函数指针
//并且其所指向的函数是,返回值为unsigned int,形参表为(unsigned int)
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n) {//递归出口的函数 
	return 0;
}

unsigned int Sum_Solution3(unsigned int n) {//递归函数
	//定义fun类型的函数指针数组f,里面存了这两个函数的函数指针 
	static fun f[2] = {Solution3_Teminator, Sum_Solution3};
	return n + f[!!n](n - 1);//和第二种解法一样的做法 
}

int main() {
	cout<<Sum_Solution3(5)<<endl;//15
	return 0;
}
