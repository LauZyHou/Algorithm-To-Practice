class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		int len = R*C;
        vector<vector<int>> ans(len);
		if(!R || !C)
			return ans;
		int xy[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
		
		vector<int> v;
		v.push_back(r0);
		v.push_back(c0);
		ans[0] = v;
		int go = 1;//有多少位置走过了
		int fx = 0;//方向
		while(go<len) {
			for(int i=0;i<fx/2+1;i++) {
				r0 += xy[fx%4][0];
				c0 += xy[fx%4][1];
				if(r0>=0 && r0<R && c0>=0 && c0<C) {
					vector<int> v;
					v.push_back(r0);
					v.push_back(c0);
					ans[go++] = v;
					if(go==len)
						goto OVER;
				}
			}
			fx++;
		}
OVER:
		return ans;
    }
};