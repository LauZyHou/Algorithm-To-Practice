class Solution {
public:
    char findTheDifference(string s, string t) {
        int slen = s.size();
		int tlen = t.size();
		int ans = 0;//ascii
		for(int i=0;i<slen;i++)
			ans^=s[i];
		for(int i=0;i<tlen;i++)
			ans^=t[i];
		return (char)ans;
    }
};