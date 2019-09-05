class Solution {
public:
	vector<int> can;
	int clen;
	vector<vector<int>> ans;
	vector<int> item;

	void dfs(int r,int t) {
		if(t==0) {
			ans.push_back(item);
			return ;
		}
		for(int i=r;i<clen && t-can[i]>=0;i++) {//剪枝:后面的只会比前面的大
			if(i>r && can[i]==can[i-1])//约束:不能重复
				continue;
			item.push_back(can[i]);
			dfs(i+1,t-can[i]);
			item.pop_back();
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
		ans = vector<vector<int>>();
		item = vector<int>();

		sort(can.begin(),can.end());
		this->can = can;
		this->clen = can.size();
		dfs(0,t);
		return ans;
    }
};