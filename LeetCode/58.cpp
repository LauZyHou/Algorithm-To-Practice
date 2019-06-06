class Solution {
public:
	bool zm(char c) {
		return c<='Z' && c>='A' || c<='z' && c>='a';
	}

    int lengthOfLastWord(string s) {
		int len = s.size();
		int b = len - 1;
		//计算末尾非空格位置
		while(b>=0 && s[b]==' ')
			b--;
		//计算单词长度
		int ans = 0;
		while(b>=0 && zm(s[b])) {
			b--;
			ans++;
		}
		return ans;
    }
};