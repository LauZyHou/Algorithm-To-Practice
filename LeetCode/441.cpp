class Solution {
public:
    int arrangeCoins(int n) {
		if(!n)
			return 0;
		//k(k+1)/2<=n
		//k(k+1)<=2n
        int k = sqrt(2.0*n);
		return k+1<=2.0*n/k ? k : k-1;
    }
};