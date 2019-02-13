#include<iostream>
using namespace std;

//วเอÜฬ๘ฬจ

class Solution {
	public:
		int jumpFloor(int n) {
			if(n<=2)
				return n;
			int pre=1;
			int nxt=2;
			int t;
			for(int i=3;i<=n;i++){
				t=pre;
				pre=nxt;
				nxt+=t;
			}
			return nxt;
		}
};


int main() {
	Solution s;
	cout<<s.jumpFloor(39);
	return 0;
}
