class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
		int len2 = arr2.size();
		unordered_map<int,int> mp;
		for(int i=0;i<len1;i++) {
			mp[arr1[i]]++;
		}
		vector<int> ans(len1);
		int j = 0;
		for(int i=0;i<len2;i++) {
			while(mp[arr2[i]]--) {
				ans[j++] = arr2[i];
			}
		}
		int r = j;
		unordered_map<int,int>::iterator it = mp.begin();
		for(;it!=mp.end();it++) {
			while(it->second>0) {//这里不直接用--因为前面做完有些已经是-1
				it->second--;
				ans[j++] = it->first;
			}
		}
		sort(ans.begin()+r,ans.end());
		return ans;
    }
};