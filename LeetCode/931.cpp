class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int xlen = A.size();
		if(!xlen)
			return 0;
		int ylen = A[0].size();
		if(!ylen)
			return 0;
		for(int i=xlen-2;i>=0;i--) {
			for(int c=0;c<ylen;c++) {
				int minbelow = A[i+1][c];
				if(c>0)
					minbelow = min(A[i+1][c-1],minbelow);
				if(c+1<ylen)
					minbelow = min(A[i+1][c+1],minbelow);
				A[i][c] += minbelow;
			}
		}
		int ans = A[0][0];
		for(int c=1;c<ylen;c++) {
			if(ans>A[0][c])
				ans = A[0][c];
		}
		return ans;
    }
};