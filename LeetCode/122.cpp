class Solution {
public:
    int maxProfit(vector<int>& p) {
        int len = p.size();
		int ans = 0;
		if(len<=1)
			return 0;
		for(int i=1;i<len;i++)
			if(p[i]>p[i-1])
				ans += p[i]-p[i-1];
		return ans;
	}
};