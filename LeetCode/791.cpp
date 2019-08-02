class Solution {
public:
	string customSortString(string s, string t) {
		int slen = s.size();
		int tlen = t.size();
		char* c = new char[tlen+1];
		c[tlen] = '\0';
		int num[26] = {0};
		for(int i=0;i<tlen;i++) {
			num[t[i]-'a']++;
		}
		int k=0;
		for(int i=0;i<slen;i++) {
			for(int j=0;j<num[s[i]-'a'];j++)
				c[k++] = s[i];
			num[s[i]-'a'] = 0;
		}
		for(int i=0;i<26;i++) {
			if(num[i]>0) {
				for(int j=0;j<num[i];j++)
					c[k++] = i+'a';
			}
		}
		string ans(c);
		delete[] c;
		return ans;
	}
};