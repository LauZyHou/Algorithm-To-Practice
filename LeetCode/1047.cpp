class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
		int len = S.size();
		for(int i=0;i<len;i++) {
			if(st.empty() || st.top()!=S[i])
				st.push(S[i]);
			else
				st.pop();
		}
		len = st.size();
		char ans[len+1];
		ans[len--] = '\0';
		while(len>=0) {
			ans[len--] = st.top();
			st.pop();
		}
		return string(ans);
    }
};