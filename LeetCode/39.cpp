class Solution {
public:
	vector<vector<int>> ans;
	
	void traceback(vector<int>& v,int begin,int end,vector<int>& path,int res) {
		if(begin>end || res<0)
			return ;
		if(res==0) {
			ans.push_back(vector<int>(path));
			return ;
		}
		//对从begin到end的每个值起始都回溯一下
		for(int i=begin;i<=end;i++) {
			path.push_back(v[i]);
			traceback(v,i,end,path,res-v[i]);//对i的begin值也就是i了,它之前的不再考虑
			path.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& v, int t) {
		ans = vector<vector<int>>();
		int len = v.size();
		//从大到小排序,然后保证比上一个大的数不再取到,这样可以去重
		sort(v.begin(),v.end(),greater<int>());
		vector<int> path;
		traceback(v,0,len-1,path,t);
		return ans;
    }
};