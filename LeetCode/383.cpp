class Solution {
public:
    bool canConstruct(string r, string m) {
		map<char,int> mp;
		for(auto s:m){
			mp[s]++;
		}
		for(auto s:r){
			mp[s]--;
			if(mp[s]<0)
				return false;
		}
		return true;
    }
};