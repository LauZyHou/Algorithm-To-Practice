class Solution {
public:
	set<vector<int>> ans;

	void traceback(int r,int n,vector<int>& v,vector<int>& sans) {
		if(r==n) {
			vector<int> tmp = sans;
			sort(tmp.begin(),tmp.end());
			ans.insert(tmp);
			return ;
		}
		//要
		sans.push_back(v[r]);
		traceback(r+1,n,v,sans);
		//不要
		sans.pop_back();
		traceback(r+1,n,v,sans);
	}

    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        ans = set<vector<int>>();
		/*
		set<int> st;
		for(int r:v)
			st.insert(r);
		vector<int> newv(st.size());
		int n=0;
		for(int r:st)
			newv[n++] = r;
		*/
		vector<int> sans;
		traceback(0,v.size(),v,sans);
		
		vector<vector<int>> real_ans;
		for(vector<int> f:ans)
			real_ans.push_back(f);
		return real_ans;
    }
};