class Solution {
public:
	string myhash(int* num) {
		string ret = "";
		for(int i=0;i<26;i++) {
			ret += "/";
			ret += to_string(num[i]);
		}
		return ret;
	}

    vector<vector<string>> groupAnagrams(vector<string>& vs) {
        int num[26];
		map<string,vector<string>> mp;
		for (string& s:vs)
        {
			memset(num,0,sizeof(int)*26);
			for(char c:s)
				num[c-'a']++;
			string hash = myhash(num);
			if(mp.find(hash)==mp.end())
				mp[hash] = vector<string>();
			mp[hash].push_back(s);
        }
		vector<vector<string>> ans;
		for(auto& m:mp) {
			ans.push_back(m.second);
		}
		return ans;
    }
};