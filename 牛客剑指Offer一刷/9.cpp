#inlude<iostream>
using namespace std;

//±‰Ã¨«‡Õ‹

class Solution {
	public:
		int jumpFloorII(int n) {
			if(n<=2)
				return n;
			int fnow=2;
			for(int i=3;i<=n;i++){
				fnow*=2;//f(n)=f(n-1)+...+f(1)=>f(n)=2f(n-1)
			}
			return fnow;
		}
};

int main() {


	return 0;
}
