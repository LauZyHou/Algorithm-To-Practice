class Solution {
public:
    int matrixScore(vector<vector<int>>& vv) {
        int xlen = vv.size();
		if(!xlen)
			return 0;
		int ylen = vv[0].size();
		if(!ylen)
			return 0;
		//将每一行第一个若是0就整行翻转变成1
		for(int i=0;i<xlen;i++) {
			if(vv[i][0]==0) {
				for(int j=0;j<ylen;j++)
					vv[i][j] = 1-vv[i][j];
			}
		}
		//从后往前扫描每一列,统计1和0的个数
		int yz = (xlen+1)/2;//阈值,行数的一半
		int xs = 1;//系数,每次往左移动一列,这个系数就要左移2
		int ans = 0;
		for(int j=ylen-1;j>=0;j--) {
			int numof1 = 0;
			for(int i=0;i<xlen;i++) {
				numof1 += vv[i][j];
			}
			if(numof1<yz)
				numof1 = xlen - numof1;
			ans += xs*numof1;
			xs <<= 1;
		}
		return ans;
    }
};