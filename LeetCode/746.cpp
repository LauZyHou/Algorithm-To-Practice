class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
		int len = c.size();
        int a[1002];
		if(!len)
			return 0;
		if(len==1)
			return c[0];
		a[0] = c[0];
		a[1] = c[1];
		for(int i=2;i<len;i++)
			a[i] = min(a[i-1]+c[i], a[i-2]+c[i]);
		return min(a[len-1], a[len-2]);
    }
};