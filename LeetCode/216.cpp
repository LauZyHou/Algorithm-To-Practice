//无重复数字的组合,不妨看成从小到大排序的排列
class Solution {
public:
	vector<vector<int>> ans;
	int n;

	//递归过程,每次放入一个数字k减少1,总和加上这个数,begin是当前起始数,从begin到9是可选的
	void traceback(int k,int sum,int begin,vector<int>& v) {
		//递归出口
		if(k==0) {
			if(sum==n){
				ans.push_back(vector<int>(v));
				return ;
			}
		}
		//剪枝:当sum达到n还没到出口,没有必要往下走
		if(sum>=n)
			return ;
		//从begin到9都可以选
		for(int i=begin;i<=9;i++) {
			v.push_back(i);
			traceback(k-1,sum+i,i+1,v);
			v.pop_back();
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
        ans = vector<vector<int>>();
		this->n = n;
		
		vector<int> r;
		traceback(k,0,1,r);
		return ans;
    }
};