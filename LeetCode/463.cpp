class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int leny = g.size();
		if(!leny)
			return 0;
		int lenx = g[0].size();
		int ans = 0;
		for(int i=0;i<leny;i++)
			for(int j=0;j<lenx;j++){
				if(!g[i][j])
					continue;
				if(i==0 || leny>1 && !g[i-1][j])
					ans++;
				if(i==leny-1 || leny>1 && !g[i+1][j])
					ans++;
				if(j==0 || lenx>1 && !g[i][j-1])
					ans++;
				if(j==lenx-1 || lenx>1 && !g[i][j+1])
					ans++;
			}
		return ans;
	}
};