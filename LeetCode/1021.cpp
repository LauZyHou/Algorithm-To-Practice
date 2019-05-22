class Solution {
public:
    string removeOuterParentheses(string s) {
		string ans = "";
		int r = 0;
		int pre = 0;
		int len = s.size();
		for(int i=0;i<len;i++) {
			if(s[i]=='(')
				r++;
			else
				r--;
			if(r==0) {
				ans += s.substr(pre+1,i-pre-1);
				pre = i+1;
			}
		}
		return ans;
    }
};