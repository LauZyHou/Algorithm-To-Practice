class Solution {
public:
    int surfaceArea(vector<vector<int>>& g) {
		/*
        int ans = 0;
		//三视图加起来再乘以2
		int ylen = grid.size();
		if(!ylen)
			return 0;
		int xlen = grid[0].size();
		if(!xlen)
			return 0;
		//俯视图
		for(int x=0;x<xlen;x++)
			for(int y=0;y<ylen;y++)
				if(grid[y][x])
					ans += 1;
		//正视图
		for(int x=0;x<xlen;x++){
			int maxi = 0;
			for(int y=0;y<ylen;y++)
				if(grid[y][x]>maxi)
					maxi = grid[y][x];
			ans += maxi;
		}
		//侧视图
		for(int y=0;y<ylen;y++){
			int maxi = 0;
			for(int x=0;x<xlen;x++)
				if(grid[y][x]>maxi)
					maxi = grid[y][x];
			ans += maxi;
		}
		return ans*2;
		*/
		//不能上面这样做,得到的不是"表面积"!
		//可以每个立方柱子计算表面积加起来
		//然后z方向的重叠面积就不用算了,相当于已经算过了
		//只要计算x,y的正负一共四个方向的重叠的部分把面积减掉就可以了
		int ans = 0;
		//xlen == ylen 
		int len = g.size();
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++){
				//小柱子的表面积
				if(g[i][j])
					ans += g[i][j]*4+2;
				//减去四个方向的重合的面积
				if(i>0)
					ans -= min(g[i][j],g[i-1][j]);
				if(j>0)
					ans -= min(g[i][j],g[i][j-1]);
				if(i<len-1)
					ans -= min(g[i][j],g[i+1][j]);
				if(j<len-1)
					ans -= min(g[i][j],g[i][j+1]);
			}
		return ans;
    }
};