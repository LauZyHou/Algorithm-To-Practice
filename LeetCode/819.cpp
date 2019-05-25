class Solution {
public:
	//判断字母+大写转小写
	char isZm(char c) {
		if(c>='a' && c<='z')
			return c;
		if(c>='A' && c<='Z')
			return c-'A'+'a';
		return '-';
	}

    string mostCommonWord(string ps, vector<string>& bv) {
        string ans;
		int ans_n = 0;
		int slen = ps.size();
		unordered_map<string,int> ban_mp,num_mp;
		for(auto bs : bv) {
			ban_mp[bs] = 1;
		}
		int j = 0;
		char c_ar[12];
		int i = 0;
		while(i<slen) {
			char tc = isZm(ps[i]);
			if('-'==tc) {
				i++;
				continue;
			}
			while(i<slen && (tc=isZm(ps[i++]))!='-') {
				c_ar[j++] = tc;
			}
			if(j) {
				c_ar[j] = '\0';
				string tmp(c_ar);
				if(!ban_mp[tmp]) {
					num_mp[tmp]++;
					if(num_mp[tmp]>ans_n) {
						ans = tmp;
						ans_n = num_mp[tmp];
					}
				}
				j = 0;
			}
		}
		return ans;
    }
};