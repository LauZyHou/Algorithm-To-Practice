class Solution {
public:
    int firstUniqChar(string s) {
        int b[26]={0};
		int len = s.size();
		for(int i=0;i<len;i++)
			b[s[i]-'a']+=1;
		for(int i=0;i<len;i++)
			if(b[s[i]-'a']==1)
				return i;
		return -1;
    }
};