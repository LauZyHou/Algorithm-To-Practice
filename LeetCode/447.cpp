class Solution {
public:
	//保存计算得到的距离的数组
	int distval[501][501];
	//计算距离
	int dist(int i,int j,vector<int> a,vector<int> b) {
		if(distval[i][j]>=0)
			return distval[i][j];
		distval[i][j] = distval[j][i] = (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
		return distval[i][j];
	}
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int len = p.size();
		//初始化保存计算得到的距离的数组
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
				distval[i][j] = -1;
		int ans = 0;
		for(int i=0;i<len;i++) {
			unordered_map<int,int> mp;
			for(int j=0;j<len;j++) {
				if(i==j)
					continue;
				int d = dist(i,j,p[i],p[j]);
				//判断在map里出现过多少次
				//例如1,2距离.现在和1,3距离一样.这个值应该记录过一次
				//然后就要加上(1,2,3)(1,3,2)两种
				//例如再加个1,5距离,那就加上(1,2,5)(1,5,2)(1,3,5)(1,5,2)四种
				//也就是乘以2
				if(mp[d]>0)
					ans += 2*mp[d];
				mp[d]++;
			}
		}
		return ans;
    }
};