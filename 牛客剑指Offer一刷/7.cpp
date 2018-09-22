#include<iostream>
using namespace std;

//FibonacciÊıÁĞ 

class Solution {
	public:
		int Fibonacci(int n) {
			if(n<0)
				return -1;
			if(n==1 || n==0)
				return n;
			int pre=0;
			int nxt=1;
			int t;
			for(int i=2;i<=n;i++){
				t=pre;
				pre=nxt;
				nxt+=t;
			}
			return nxt;
		}
};

int main() {
	Solution s;
	cout<<s.Fibonacci(39);
	return 0;
}
