class Solution {
public:
	vector<int> vv;
	vector<vector<int>> ans;
	int len;

	//排列树回溯
	void backtrack(int i) {
		if(i==len-1) {
			ans.push_back(vv);
			return ;
		}
		for(int j=i;j<len;j++) {
			swap(vv[i],vv[j]);
			backtrack(i+1);
			swap(vv[i],vv[j]);
		}
	}

    vector<vector<int>> permute(vector<int>& v) {
		vv = v;
        ans = vector<vector<int>>();
		len = v.size();
		backtrack(0);
		return ans;
    }
};