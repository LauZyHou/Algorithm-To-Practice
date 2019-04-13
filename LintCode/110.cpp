class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &g) {
        int xlen = g.size();
		if(!xlen)
			return 0;
		int ylen = g[0].size();
		if(!ylen)
			return 0;
		//horizenal
		for(int j=1;j<ylen;j++)
			g[0][j]+=g[0][j-1];
		//vertical
		for(int i=1;i<xlen;i++)
			g[i][0]+=g[i-1][0];
		//others
		for(int i=1;i<xlen;i++){
			for(int j=1;j<ylen;j++){
				g[i][j] += min(g[i-1][j],g[i][j-1]);
			}
		}
		return g[xlen-1][ylen-1];
    }
};