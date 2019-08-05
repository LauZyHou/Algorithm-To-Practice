class Solution {
public:
	vector<int> pathInZigZagTree(int r) {
		vector<int> ans;
		ans.push_back(r);
		int lev = floor(log2(r))+1;
		while(r!=1) {
			if((lev&1)==0) {
				int a = pow(2,lev-1);
				int b = pow(2,lev)-1;
				int ctpt = a+b-r;
				r = ctpt/2;
				lev--;
			} else {
				r /= 2;
				lev--;
				int a = pow(2,lev-1);
				int b = pow(2,lev)-1;
				r = a+b-r;
			}
			ans.push_back(r);
		}
		reverse(ans.begin(),ans.end());
		return ans;
	}
};