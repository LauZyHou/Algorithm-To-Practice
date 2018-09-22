#include<iostream>
using namespace std;

class Solution {
	public:
		double Power(double base, int exponent) {
			if(0==exponent || 1==base)
				return 1;
			bool isFu=false;
			if(0>exponent) {
				isFu=true;
				exponent=-exponent;
			}

			double below=base;
			//quick
			if(exponent<10) {
				for(int i=1;i<exponent;i++)
					below*=base;
			} else {
				below=Power(base,exponent/2);
				below*=below;
				if(exponent & 1==1)//odd
					below*=base;
			}
			if(isFu)
				return 1/below;
			return below;
		}
};

int main() {


	return 0;
}
