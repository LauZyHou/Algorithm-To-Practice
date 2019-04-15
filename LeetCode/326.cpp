class Solution {
public:
    bool isPowerOfThree(int n) {
		if(0>=n) return false;
		//因为3是个质数,只要找到最大的3的x次幂,然后3的幂一定是其真因子
		int x=3;
		while(x<(INT_MAX/3))//防溢出的最大值
			x*=3;
		return x%n==0;
    }
};