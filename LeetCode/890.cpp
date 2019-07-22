class Solution {
public:
	//转为唯一的模式表示:从a开始排列
	string change(string s) {
		char now = 'a';
		map<char,char> mp;//模式变换
		int slen = s.size();
		char* array = new char[slen+1];
		for(int i=0;i<slen;i++) {
			if(mp.find(s[i])!=mp.end())
				array[i] = mp[s[i]];
			else {
				mp[s[i]] = now;
				array[i] = now++;
			}
		}
		array[slen] = '\0';
		string ret(array);
		delete[] array;
		return ret;
	}

    vector<string> findAndReplacePattern(vector<string>& wv, string ps) {
		vector<string> ans;
		string ok = change(ps);//得到固定模式
		int pslen = ps.size();
		for(string w:wv) {
			int wlen = w.size();
			if(wlen!=pslen)
				continue;
			string wok = change(w);
			if(ok==wok)
				ans.push_back(w);
		}
		return ans;
    }
};