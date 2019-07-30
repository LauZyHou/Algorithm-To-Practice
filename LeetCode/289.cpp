class Solution {
public:
    void gameOfLife(vector<vector<int>>& vv) {
		//活-活:1
		//活-死:2
		//死-死:0
		//死-活:-1
		//这样只要>0就说明之前是活的
        int xlen = vv.size();
		if(!xlen)
			return ;
		int ylen = vv[0].size();
		if(!ylen)
			return ;
		for(int i=0;i<xlen;i++) {
			for(int j=0;j<ylen;j++) {
				int huo = 0;
				if(i>0) {//上面一排有东西
					if(vv[i-1][j]>0)
						huo++;
					if(j>0 && vv[i-1][j-1]>0)
						huo++;
					if(j<ylen-1 && vv[i-1][j+1]>0)
						huo++;
				}
				if(i<xlen-1) {//下面一排有东西
					if(vv[i+1][j]>0)
						huo++;
					if(j>0 && vv[i+1][j-1]>0)
						huo++;
					if(j<ylen-1 && vv[i+1][j+1]>0)
						huo++;
				}
				if(j>0 && vv[i][j-1]>0)//左边
					huo++;
				if(j<ylen-1 && vv[i][j+1]>0)//右边
					huo++;
				//做死活变化
				if(huo<2 && vv[i][j]==1)
					vv[i][j] = 2;
				if(huo>3 && vv[i][j]==1)
					vv[i][j] = 2;
				if(huo==3 && vv[i][j]==0)
					vv[i][j] = -1;
			}
		}
		//把2和-1变成0和1
		for(int i=0;i<xlen;i++)
			for(int j=0;j<ylen;j++)
				if(vv[i][j]==2)
					vv[i][j] = 0;
				else if(vv[i][j]==-1)
					vv[i][j] = 1;
    }
};