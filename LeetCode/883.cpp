class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
		int rows = grid.size();
		if(rows==0)
			return 0;
		int cols = grid[0].size();
		if(cols==0)
			return 0;
		//从上往下看
		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++)
				if(grid[i][j]>0)
					ans++;
		//顺着x的方向看
		for(int j=0;j<cols;j++){
			//find max
			int maxval = 0;
			for(int i=0;i<rows;i++){
				if(grid[i][j]>maxval)
					maxval = grid[i][j];
			}
			ans+=maxval;
		}
		//顺着y的方向看
		for(int i=0;i<rows;i++){
			int maxval = 0;
			for(int j=0;j<cols;j++)
				if(grid[i][j]>maxval)
					maxval = grid[i][j];
			ans+=maxval;
		}
		return ans;
	}
};