class Solution {
public:
	//检查是1到9非5的数字
	bool check1to9expt5(int a) {
		return a>=1 && a<=9 && a!=5;
	}

	int p1[4][2] = {{0,0},{0,1},{0,2},{1,2}};
    int p2[4][2] = {{2,2},{2,1},{2,0},{1,0}};

	int numMagicSquaresInside(vector<vector<int>>& g) {
		int ans = 0;
        int xlen = g.size();
		if(xlen<3)
			return 0;
		int ylen = g[0].size();
		if(ylen<3)
			return 0;
		//cout<<"xlen="<<xlen<<",ylen="<<ylen<<endl;
		for(int i=0;i<xlen-2;i++) {
			for(int j=0;j<ylen-2;j++) {
				//cout<<"本次i="<<i<<",j="<<j<<endl;
				//i,j是3x3幻方的左上角
				if(g[i+1][j+1]!=5)
					continue;
				//cout<<"验证A通过"<<endl;
				//判断5两臂的元素
				int a[11] = {false};
				bool check = true;
				for(int k=0;k<4;k++) {
					if(!check1to9expt5(g[i+p1[k][0]][j+p1[k][1]]) || 
						a[g[i+p1[k][0]][j+p1[k][1]]] || 
						g[i+p1[k][0]][j+p1[k][1]]+g[i+p2[k][0]][j+p2[k][1]]!=10) {
						check = false;
						break;
					}
					a[g[i+p1[k][0]][j+p1[k][1]]] = true;
					a[g[i+p2[k][0]][j+p2[k][1]]] = true;
				}
				if(false==check)
					continue;
				//cout<<"验证B通过"<<endl;
				//判断4条边加起来的值
				if(g[i][j]+g[i][j+1]+g[i][j+2]!=15 ||
					g[i][j+2]+g[i+1][j+2]+g[i+2][j+2]!=15 ||
					g[i+2][j+2]+g[i+2][j+1]+g[i+2][j]!=15 ||
					g[i+2][j]+g[i+1][j]+g[i][j]!=15)
					continue;
				ans++;
				//cout<<"验证C通过"<<endl;
			}
		}
		return ans;
    }
};