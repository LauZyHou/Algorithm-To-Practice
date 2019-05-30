class Solution {
public:
    int findPairs(vector<int>& v, int k) {
		if(k<0)
			return 0;
		unordered_map<int,int> mp;//每个数字出现次数
		int len = v.size();
		for(int i=0;i<len;i++) {
			if(mp.find(v[i])==mp.end())
				mp[v[i]] = 0;
			mp[v[i]]+=1;
		}
		int ans = 0;
		unordered_map<int,int>::iterator it;
		//查询过程
		if(k==0) {
			for(it=mp.begin();it!=mp.end();it++) {
				//至少有2个才能组出一对来
				if((*it).second>=2)
					ans++;
			}
		}
		else {
			for(it=mp.begin();it!=mp.end();it++) {
				if(mp.find((*it).first+k)!=mp.end())
					ans++;
			}
		}
		return ans;
    }
};