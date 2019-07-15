class Solution {
public:
    vector<int> countBits(int num) {
        //P(x) = P(x>>1) + x Mod 2
		vector<int> ans(num+1);
		ans[0] = 0;
		for(int i=1;i<=num;i++)
			ans[i] = ans[(i>>1)] + (i&1);
		return ans;
    }
};