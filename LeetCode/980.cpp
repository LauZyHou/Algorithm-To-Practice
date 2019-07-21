//-1:障碍物,1:起始点,2:终止点
//用3表示自己走过的路,这些路也是不能再走了
class Solution {
public:
	int ans;
	int sx,sy,gx,gy;//起始点xy和终止点xy坐标
	int xlen,ylen;
	//上下左右四个方向
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};

	//当前要走到x,y位置,已经走过了num个数字
	void dfs(int x,int y,int num,vector<vector<int>>& vv) {
		//递归出口,走到gxgy位置
		if(x==gx && y==gy) {
			if(num==0)
				ans++;
			return ;
		}

		//递归过程,先把当前位置置为走过了(如果是起始的1也就不用了),然后走上下左右四个方向
		if(vv[x][y]==0)
			vv[x][y] = 3;
		for(int i=0;i<4;i++) {
			int next_x = x+dx[i];
			int next_y = y+dy[i];
			//0或者2都可以走,-1或者1或者3都不能走
			if(next_x>=0 && next_x<xlen && next_y>=0 && next_y<ylen 
				&& vv[next_x][next_y]%2==0) {
				dfs(next_x,next_y,num-1,vv);
			}
		}
		//回退前把这个走过的路径清除
		if(vv[x][y]==3)
			vv[x][y] = 0;
	}

    int uniquePathsIII(vector<vector<int>>& vv) {
		xlen = vv.size();
		if(!xlen)
			return 0;
		ylen = vv[0].size();
		if(!ylen)
			return 0;
		ans = 0;

		//寻找起始点,终止点,统计非障碍物数目
		int num = 0;
		for(int i=0;i<xlen;i++) {
			for(int j=0;j<ylen;j++) {
				if(vv[i][j]!=-1)
					num++;
				if(vv[i][j]==1) {
					sx = i;
					sy = j;
				}
				else if(vv[i][j]==2) {
					gx = i;
					gy = j;
				}
			}
		}

		//回溯过程(这里num-1是去掉最开始的那个起始点)
		dfs(sx,sy,num-1,vv);
		return ans;
    }
};