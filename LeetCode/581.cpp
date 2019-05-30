class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
		int len = v.size();
		vector<int> st = v;
		sort(st.begin(),st.end());
		int i = 0;
		for(;i<len;i++) {
			if(v[i]!=st[i])
				break;
		}
		int j = len - 1;
		for(;j>=0;j--) {
			if(v[j]!=st[j])
				break;
		}
		return j>=i ? j - i + 1 : 0;
    }
};