class Solution {
public:
    vector<int> constructArray(int n, int k) {
		vector<int> ans(n);
		int now = 1;
		for(int i=0;i<=k;i++) {
			if((i&1)==0)
				ans[i] = now++;
		}
		for(int i=k;i>=0;i--) {
			if((i&1)==1)
				ans[i] = now++;
		}
		for(int i=k+1;i<n;i++)
			ans[i] = now++;
		return ans;
    }
};