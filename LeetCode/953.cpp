class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mp[26];//记录26个英文字母的index
		for(int i=0;i<26;i++)
			mp[order[i]-'a'] = i;
		int len = words.size();
		for(int i=1;i<len;i++){
			int len1 = words[i-1].size();
			int len2 = words[i].size();
			int slen = min(len1,len2);
			int j = 0;
			for(;j<slen;j++)
				if(mp[words[i-1][j]-'a']>mp[words[i][j]-'a'])
					return false;
				else if(mp[words[i-1][j]-'a']<mp[words[i][j]-'a'])
					goto CONTI;
			if(len1>len2)
				return false;
			CONTI:
				;
		}
		return true;
    }
};