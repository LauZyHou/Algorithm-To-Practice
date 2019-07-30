class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int l = 0;
		int r = 0;
		int len = seq.size();
		vector<int> ans(seq.size());
		for(int i=0;i<len;i++) {
			if(seq[i]=='(') {
				ans[i] = l;
				l = (l+1)%2;
			}
			else {
				ans[i] = r;
				r = (r+1)%2;
			}
		}
		return ans;
    }
};