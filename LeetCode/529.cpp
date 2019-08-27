class Solution {
public:
	int xlen,ylen;
	int r[8] = {-1,-1,-1,0,1,1,1,0};
	int l[8] = {-1,0,1,1,1,0,-1,-1};

	void dfs(vector<vector<char>>& vv,int x,int y) {
		int cnt = 0;
		for(int i=0;i<8;i++) {
			if(x+r[i]>=xlen || x+r[i]<0 || y+l[i]>=ylen || y+l[i]<0)
				continue;
			if(vv[x+r[i]][y+l[i]]=='M')
				cnt++;
		}
		if(cnt==0) {
			vv[x][y] = 'B';
			for(int i=0;i<8;i++) {
				if(x+r[i]>=xlen || x+r[i]<0 || y+l[i]>=ylen || y+l[i]<0)
					continue;
				if(vv[x+r[i]][y+l[i]]=='E')
					dfs(vv,x+r[i],y+l[i]);
			}
		} else {
			vv[x][y] = '0'+cnt;
		}
	}

    vector<vector<char>> updateBoard(vector<vector<char>>& vv, vector<int>& c) {
		xlen = vv.size();
		if(!xlen)
			return vv;
		ylen = vv[0].size();
		if(!ylen)
			return vv;
		if(vv[c[0]][c[1]]=='M') {
			vv[c[0]][c[1]]='X';
			return vv;
		}
		dfs(vv,c[0],c[1]);
		return vv;
    }
};