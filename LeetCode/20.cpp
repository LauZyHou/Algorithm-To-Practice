class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
		stack<char> st;
		int i = 0;
		while(i<len){
			if(s[i]=='[' || s[i]=='(' || s[i]=='{') {
				st.push(s[i]);
			}else {
				if(st.empty())
					return false;
				char c = st.top();
				st.pop();
				if(!(c=='(' && s[i]==')' || c=='[' && s[i]==']' || c=='{' && s[i]=='}'))
					return false;
			}
			i++;
		}
		return st.empty();
    }
};