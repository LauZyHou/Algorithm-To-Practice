class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int len = grid.size();
		vector<int> rowmax(len);
		vector<int> colmax(len);
		for(int i=0;i<len;i++) {
			int now = grid[i][0];
			for(int j=1;j<len;j++) {
				if(grid[i][j]>now) {
					now = grid[i][j];
				}
			}
			rowmax[i] = now;
		}
		for(int j=0;j<len;j++) {
			int now = grid[0][j];
			for(int i=1;i<len;i++) {
				if(grid[i][j]>now) {
					now = grid[i][j];
				}
			}
			colmax[j] = now;
		}
		int ans = 0;
		for(int i=0;i<len;i++) {
			for(int j=0;j<len;j++) {
				int val = min(rowmax[i],colmax[j]) - grid[i][j];
				if(val>0)
					ans += val;
			}
		}
		return ans;
    }
};