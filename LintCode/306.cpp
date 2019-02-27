class Solution {
public:
	int v[1000]={0,0,1};
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
	int fibonacci(int n) {
		if(n<=1)
			return 0;
        if(v[n])
			return v[n];
		v[n]=fibonacci(n-1)+fibonacci(n-2);
		return v[n];
    }
};