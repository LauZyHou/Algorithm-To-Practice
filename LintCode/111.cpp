class Solution {
private:
	int a[100]={0,1,2};
	int now = 2;
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if(n<=now)
			return a[n];
		for(int i=now+1;i<=n;i++)
			a[i]=a[i-1]+a[i-2];
		return a[n];
    }
};