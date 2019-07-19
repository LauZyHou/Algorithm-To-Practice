class Solution {
public:
	vector<vector<int>> ans;
	vector<int> now;
	int k;
	int n;

	void backtrack(int t) {
		//剪枝,如果剩下的数全放进来都不够k个,就直接返回
		if(now.size() + n-t+1 < k)
			return ;
		//回溯过程
		now.push_back(t+1);//t是索引,实际数字从1到n

		//递归出口:已经到了k这么多个元素了
		if(now.size()==k) {
			ans.push_back(vector<int>(now));
			now.pop_back();
			return ;
		}

		for(int i=t+1;i<n;i++)//对其后的每一个数字都回溯一遍
			backtrack(i);
		now.pop_back();//最后维护好这一层
	}

    vector<vector<int>> combine(int n, int k) {
		ans = vector<vector<int>>();
		now = vector<int>();
		this->k = k;
		this->n = n;
		for(int i=0;i<=n-k;i++)//从i位置开头往后组合k个数字出来
			backtrack(i);
		return ans;
    }
};