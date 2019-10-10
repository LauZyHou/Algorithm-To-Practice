class Solution {
public:
	int rlen;
	int clen;
	int ans;

	int dfs(vector<vector<int>>& v,int r,int c) {
		v[r][c] = 0;
		int now = 1;
		if(r+1<rlen && v[r+1][c]==1)
			now += dfs(v,r+1,c);
		if(r-1>=0 && v[r-1][c]==1)
			now += dfs(v,r-1,c);
		if(c+1<clen && v[r][c+1]==1)
			now += dfs(v,r,c+1);
		if(c-1>=0 && v[r][c-1]==1)
			now += dfs(v,r,c-1);
		return now;
	}

    int maxAreaOfIsland(vector<vector<int>>& vv) {
        rlen = vv.size();
		if(!rlen)
			return 0;
		clen = vv[0].size();
		if(!clen)
			return 0;
		ans = 0;
		for(int i=0;i<rlen;i++)
			for(int j=0;j<clen;j++) {
				if(vv[i][j]==1)
					ans = max(ans, dfs(vv,i,j));
			}
		return ans;
    }
};