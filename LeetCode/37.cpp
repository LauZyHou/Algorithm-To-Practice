class Solution {
public:
	bool ruse[9][10] = {false};//9行9数字(1~9)
	bool cuse[9][10] = {false};//9列9数字
	bool buse[3][3][10] = {false};//3*3个方格9数字
	int rlen;
	int clen;

	void init() {
		for(int i=0;i<9;i++)
			for(int j=1;j<10;j++)
				ruse[i][j] = cuse[i][j] = false;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=1;k<10;k++)
					buse[i][j][k] = false;
	}

	//递归填充
	bool rec(vector<vector<char>>& vv,int r,int c) {
		//一行填充完
		if(c==clen) {
			c = 0;
			r++;
			if(r==rlen)//每行都填充过了
				return true;//结束了
		}
		//非空,向右填充下一个位置
		if(vv[r][c]!='.')
			return rec(vv,r,c+1);
		//空,进行填充,遍历每个数字
		for(int num=1;num<=9;num++) {
			//检查bool表看看是否可用
			bool canuse = !ruse[r][num] && !cuse[c][num] && !buse[r/3][c/3][num];
			if(!canuse)
				continue;
			//可用,用一下试试继续往下递归能不能得到true
			ruse[r][num] = true;
			cuse[c][num] = true;
			buse[r/3][c/3][num] = true;
			vv[r][c] = char(num+'0');

			if(rec(vv,r,c+1))
				return true;

			//不能得到true,还原可用状态并尝试下一个数字
			ruse[r][num] = false;
			cuse[c][num] = false;
			buse[r/3][c/3][num] = false;
			//vv[r][c] = '.';
		}
		//只需要在这里还原
		vv[r][c] = '.';
		//到最后都没找到可用的数字,说明是前面的选择有问题,返回false
		return false;
	}

    void solveSudoku(vector<vector<char>>& vv) {
        rlen = vv.size();
		if(!rlen)
			return ;
		clen = vv[0].size();
		if(!clen)
			return ;

		init();

		//初始化,vv中已经有的数字就置为true
		for(int i=0;i<rlen;i++) {
			for(int j=0;j<clen;j++) {
				int n = vv[i][j]-'0';
				if(1<=n && n<=9)
					ruse[i][n] = cuse[j][n] = buse[i/3][j/3][n] = true;
			}
		}
		//递归填充
		rec(vv,0,0);
    }
};