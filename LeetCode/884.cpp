class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> mp;
		string temp;
		stringstream ss(A);
		while(ss>>temp)
			mp[temp]=mp[temp]?mp[temp]+1:1;
		ss = stringstream(B);
		while(ss>>temp)
			mp[temp]=mp[temp]?mp[temp]+1:1;
		unordered_map<string,int>::iterator it;
		vector<string> ans;
		for(it=mp.begin();it!=mp.end();it++)
			if(it->second==1)
				ans.push_back(it->first);
		return ans;
    }
};