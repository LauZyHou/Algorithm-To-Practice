class Solution {
public:
	int xlen;
	int ylen;

	void dfs(vector<vector<char>>& v,int x,int y) {
		v[x][y] = '.';//搜过的位置
		//因为调用的时候是从上到下,从左往右遍历的,所以不必考虑左边或者上边的点
		if(x+1<xlen && v[x+1][y]=='X')
			dfs(v,x+1,y);
		if(y+1<ylen && v[x][y+1]=='X')
			dfs(v,x,y+1);
	}

    int countBattleships(vector<vector<char>>& v) {
        xlen = v.size();
		if(!xlen)
			return 0;
		ylen = v[0].size();
		if(!ylen)
			return 0;
		int ans = 0;
		for(int x=0;x<xlen;x++) {
			for(int y=0;y<ylen;y++) {
				if(v[x][y]=='X') {
					ans++;
					dfs(v,x,y);
				}
			}
		}
		return ans;
    }
};