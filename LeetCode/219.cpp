class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
		int len = v.size();
		unordered_map<int,int> mp;//数组值,下标
		for(int i=0;i<len;i++) {
			if(mp.find(v[i])==mp.end())
				mp[v[i]] = i;
			else
				if(i-mp[v[i]]<=k)
					return true;
				else
					mp[v[i]] = i;
		}
		return false;
    }
};