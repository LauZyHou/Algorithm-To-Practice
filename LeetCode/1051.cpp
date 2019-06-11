class Solution {
public:
    int heightChecker(vector<int>& v) {
		int len = v.size();
		vector<int> r = v;
		sort(r.begin(),r.end());
		int ans = 0;
		for(int i=0;i<len;i++) {
			if(v[i]!=r[i])
				ans++;
		}
		return ans;
    }
};