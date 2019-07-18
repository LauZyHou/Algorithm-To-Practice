class Solution {
public:
	vector<vector<int>> ans;	
	int n;

	void dfs(vector<vector<int>>& g, vector<int>&v, int t) {//v用引用免得每次拷贝构造
		v.push_back(t);
		if(t==n-1) {//递归出口,找到了到n-1的路径
			ans.push_back(vector<int>(v));//不能把引用扔进去
			v.pop_back();
			return ;
		}
		for(auto r:g[t]) {
			dfs(g,v,r);
		}
		v.pop_back();//维护好本层,t用完要退回去
	}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        ans = vector<vector<int>>();
		n = g.size();
		vector<int> v;//存路径
		dfs(g,v,0);
		return ans;
    }
};