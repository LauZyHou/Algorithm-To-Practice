class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
		int ans = 0;
		unordered_map<int,int> mp;
		for(auto item : time){
			mp[item%60]++;
		}
		ans += mp[0]*(mp[0]-1)/2;
		for(int i=1;i<30;i++){
			ans += mp[i]*mp[60-i];
		}
		ans += mp[30]*(mp[30]-1)/2;
		return ans;
    }
};