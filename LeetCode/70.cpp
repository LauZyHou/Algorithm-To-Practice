class Solution {
private:
	int a[100];
	int cnt=2;
public:
	Solution(){
		a[0]=a[1]=1;
		a[2]=2;
	}
    int climbStairs(int n) {
		for(;cnt<=n;cnt++)
			a[cnt]=a[cnt-1]+a[cnt-2];
		return a[n];
    }
};