class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
		int len1 = l1.size();
		int len2 = l2.size();
		map<string,int> mp;//for 1
		vector<string> ans;
		int sum = INT_MAX;
		for(int i=0;i<len1;i++){
			mp[l1[i]] = i;
		}
		for(int i=0;i<len2;i++){
			if(mp.find(l2[i])==mp.end())
				continue;
			int ifor1 = mp[l2[i]];
			if(i+ifor1<sum){
				sum = i + ifor1;
				ans.clear();
				ans.push_back(l2[i]);
			}else if(i+ifor1==sum)
				ans.push_back(l2[i]);
		}
		return ans;
    }
};