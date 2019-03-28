class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0},b[26]={0};
		int slen = s.size();
		int tlen = t.size();
		for(int i=0;i<slen;i++)
			a[s[i]-'a']++;
		for(int i=0;i<tlen;i++)
			b[t[i]-'a']++;
		for(int i=0;i<26;i++)
			if(a[i]!=b[i])
				return false;
		return true;
    }
};