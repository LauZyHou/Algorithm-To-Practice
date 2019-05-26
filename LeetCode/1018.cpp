class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
		int len = A.size();
		int val = 0;
		vector<bool> ans(len);
		for(int i=0;i<len;i++) {
			val = (val*2+A[i])%5;
			if(val%5==0)
				ans[i] = true;
			else
				ans[i] = false;
		}
		return ans;
    }
};