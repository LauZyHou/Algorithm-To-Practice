#include<iostream>
using namespace std;

class Solution {
	public:
		int rectCover(int n) {
			if(n<=2)
				return n;
			int t;
			int pre=1;
			int nxt=2;
			for(int i=3;i<=n;i++){
				t=pre;
				pre=nxt;
				nxt+=t;
			}
			return nxt;
		}
};

int main() {


	return 0;
}
