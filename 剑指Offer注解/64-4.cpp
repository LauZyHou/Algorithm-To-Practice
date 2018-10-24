#include<bits/stdc++.h>
using namespace std;

//当输入具体的n时,Sum_Solution4<n>::N如果没有定义
//则编译需要的这个枚举量N = Sum_Solution4<n - 1>::N + n自然会递归编译 
template<unsigned int n> struct Sum_Solution4 {
	enum Value { N = Sum_Solution4<n - 1>::N + n};//直到n-1为1时会直接找到下面的Sum_Solution4<1> 
};

template<> struct Sum_Solution4<1> {//编译器递归的出口
	//enum 枚举类型名 {枚举表};
	enum Value { N = 1};
};

//书上没有这个,如果求Sum_Solution4<0>就得不到
//所以单独定义这个特殊值
template<> struct Sum_Solution4<0> { 
	enum Value { N = 0};
};


int main() {
	//取其中的枚举量N 
	cout<<Sum_Solution4<5>::N<<endl;//15
	return 0;
}
