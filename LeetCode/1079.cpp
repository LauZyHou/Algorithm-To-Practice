class Solution {
public:
	int mp[26];
	int ans;

	void traceback() {
		//遍历表,对出现次数>0的将其使用然后继续向下递归
		for(int i=0;i<26;i++) {
			if(mp[i]==0)
				continue;
			ans++;//已经有的串补上当前这个字母
			mp[i] -= 1;//这个字母使用掉了一个

			traceback();//继续向下递归

			mp[i] += 1;//回来之后,将这个字母补上
		}
	}

    int numTilePossibilities(string s) {
		memset(mp,0,sizeof(int)*26);
		ans = 0;

		for(char c:s) {
			mp[c-'A']++;
		}
		traceback();
		return ans;
    }
};