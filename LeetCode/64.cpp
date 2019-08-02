class Solution {
public:
	int minPathSum(vector<vector<int>>& vv) {
		int xlen = vv.size();
		if(!xlen)
			return 0;
		int ylen = vv[0].size();
		if(!ylen)
			return 0;
		for(int i=1;i<xlen;i++) {
			vv[i][0] += vv[i-1][0];
		}
		for(int j=1;j<ylen;j++) {
			vv[0][j] += vv[0][j-1];
		}
		for(int i=1;i<xlen;i++) {
			for(int j=1;j<ylen;j++) {
				vv[i][j] += min(vv[i-1][j],vv[i][j-1]);
			}
		}
		return vv[xlen-1][ylen-1];
	}
};