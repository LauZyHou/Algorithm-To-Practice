#include<bits/stdc++.h>
using namespace std;

class A;//类A的声明,因为在定义之前就写了下面这句用A*定义的数组 
A* Array[2];//存两个A类型对象指针的数组 

class A {//抽象基类A 
	public:
		//A中的Sum将作为递归出口调用的函数
		virtual unsigned int Sum (unsigned int n) {
			return 0;
		}
};

class B: public A {//B类是A类的子类,并override这个Sum函数 
	public:
		//B中的Sum将作为递归调用的Sum 
		virtual unsigned int Sum (unsigned int n) {
			//当n非0时,!!n==true也即1;当n为0时,!!n==false也即0
			//所以递归调用到最后n=0时将调用Array[0]的Sum方法 
			return Array[!!n]->Sum(n-1) + n;
			//虚函数的主要作用是在派生类与基础之间产生多态性
			//主要是这种泛型让两个方法重名,其实也没利用到多态 
		}
};

int Sum_Solution2(int n) {
	A a;
	B b;
	//将实例地址绑定到数组中 
	Array[0] = &a; 
	Array[1] = &b;

	//调用B的Sum方法开始 
	int value = Array[1]->Sum(n);

	return value;
}

int main() {
	cout<<Sum_Solution2(5)<<endl;//15
	return 0;
}
