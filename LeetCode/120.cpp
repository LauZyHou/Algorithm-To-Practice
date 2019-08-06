class Solution {
public:
	int minimumTotal(vector<vector<int>>& vv) {
		int len = vv.size();
		int ansmin = INT_MAX;
		for(int i=1;i<len;i++) {
			//j=0时
			vv[i][0] += vv[i-1][0];
			//0<j<i时
			for(int j=1;j<i;j++) {
				vv[i][j] += min(vv[i-1][j-1],vv[i-1][j]);
			}
			//j=i时
			vv[i][i] += vv[i-1][i-1];
		}
		for(int j=0;j<len;j++)
			if(vv[len-1][j]<ansmin)
				ansmin = vv[len-1][j];
		return ansmin;
	}
};