class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& w) {
		int len = s.size();
		int a[26] = {0};
		for(int i=0;i<len;i++){
			char c = s[i];
			if('a'<=c && c<='z')
				a[c-'a']++;
			else if('A'<=c && c<='Z')
				a[c-'A']++;
		}
		int nowmin = INT_MAX;
		int wlen = w.size();
		int idx = -1;
		for(int i=0;i<wlen;i++){
			int nlen = w[i].size();
			if(nlen>=nowmin)
				continue;
			int b[26];
			for(int j=0;j<26;j++)
				b[j] = a[j];
			for(int j=0;j<nlen;j++){
				b[w[i][j]-'a']--;
			}
			//check
			int j=0;
			for(;j<26;j++)
				if(b[j]>0)
					break;
			if(j==26){
				idx = i;
				nowmin = nlen;
			}
		}
		return w[idx];
    }
};