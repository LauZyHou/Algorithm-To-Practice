#include<bits/stdc++.h>
using namespace std;

int LastRemaining_Solution2(unsigned int n, unsigned int m) {
	if(n < 1 || m < 1)//输入合法性 
		return -1;
	
	//相当于书上的f(n,m)
	//当n=1时因为只有一个数字0,没有东西可删所以就是0 
	int last = 0;
	for (int i = 2; i <= n; i ++)//n从2开始一直到输入的n 
		last = (last + m) % i;//新的f(n,m)=(旧的f(n,m)+m)%n

	return last;
}

int main() {
	cout<<LastRemaining_Solution2(4000,997)<<endl;//1027
	return 0;
}
