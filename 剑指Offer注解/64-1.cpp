#include<bits/stdc++.h>
using namespace std;

class Temp {
	private:
		//两个都是静态变量,所有实例共享 
		static unsigned int N;//当前要加的数字N 
		static unsigned int Sum;//数字总和Sum 

	public:
		Temp() {//在构造器里实现N的自增和加到Sum上 
			++ N;
			Sum += N;
		}

		static void Reset() {//重置 
			N = 0;
			Sum = 0;
		}
		static unsigned int GetSum() {//获取总和 
			return Sum;
		}
};

//static成员变量需要在类定义体外进行初始化与定义
//因为static数据成员独立该类的任意对象存在
//它是与类关联的对象,不与类对象关联
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n) {
	Temp::Reset();//重置静态bianl 

	Temp *a = new Temp[n];//建立n个对象,调用了n次构造器 
	delete []a;//销毁它们 
	a = NULL;//避免野指针 

	return Temp::GetSum();//其中的静态变量已经改变,获取一下 
}

int main() {
	cout<<Sum_Solution1(5)<<endl;//15
	return 0;
}
