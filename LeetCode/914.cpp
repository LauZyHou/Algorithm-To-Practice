class Solution {
public:
    bool hasGroupsSizeX(vector<int>& v) {
        unordered_map<int,int> mp;
		for(auto a : v) {
			mp[a]++;
		}
		unordered_map<int,int>::iterator it = mp.begin();
		if(it==mp.end())
			return false;
		int ans = (*it).second;
		it++;
		for(;it!=mp.end();it++) {
			ans = gcd(ans, (*it).second);
			if(ans<2)
				return false;
		}
		return ans>1;
    }
};