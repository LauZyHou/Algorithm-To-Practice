class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
		//放入一个空集
		ans.push_back(vector<int>());//目前状态[[],]
		//依次读取nums中的数字,然后放入和并入ans
		for(int n:nums) {
			vector<vector<int>> tmp = ans;
			int len = tmp.size();
			for(int i=0;i<len;i++)
				tmp[i].push_back(n);
			//合并进来
			ans.insert(ans.end(),tmp.begin(),tmp.end());
		}
		return ans;
    }
};