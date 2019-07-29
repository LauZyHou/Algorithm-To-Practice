class Solution {
public:
	int n;
	vector<vector<string>> ans;
	int* colIndex;//记录每一行都在哪一列
	bool* colIsFree;//记录每一列是否可用
	bool *zhu,*fu;//主对角线,副对角线是否可用

	//添加解
	void addAns() {
		vector<string> map(n);
		for(int i=0;i<n;i++) {
			string s(n,'.');
			s[colIndex[i]] = 'Q';
			map[i] = s;
		}
		ans.push_back(map);
	}

	//测试该点是否能避免被攻击,即测试可用性
	bool check(int r,int c) {
		//列
		if(!colIsFree[c])
			return false;
		//所在主对角线
		if(!zhu[r-c+n-1])
			return false;
		//所在副对角线
		if(!fu[r+c])
			return false;
		return true;
	}

	//设置可达点被使用
	void setUsed(int r,int c) {
		//记录位置
		colIndex[r] = c;
		//列
		colIsFree[c] = false;
		//主对角线
		zhu[r-c+n-1] = false;
		//副对角线
		fu[r+c] = false;
	}

	//恢复可达点为可用
	void reset(int r,int c) {
		//位置不用清除,写入时即会被覆盖
		//列
		colIsFree[c] = true;
		//主对角线
		zhu[r-c+n-1] = true;
		//副对角线
		fu[r+c] = true;
	}

	//回溯过程,传入当前要走的行索引
	void traceback(int row) {
		if(row==n) {
			this->addAns();
			return ;
		}
		for(int i=0;i<n;i++) {//对该行的每一列
			if(this->check(row,i)) {//检查此位置通过
				this->setUsed(row,i);//将该点的可达点都封锁
				traceback(row+1);//向下回溯
				this->reset(row,i);//将该点的可达点恢复
			}
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		ans = vector<vector<string>>();
		this->n = n;
		colIndex = new int[n];
		colIsFree = new bool[n];
		zhu = new bool[2*n-1];
		fu = new bool[2*n-1];
		for(int i=0;i<n;i++)
			colIsFree[i] = true;
		for(int i=0;i<2*n-1;i++) {
			zhu[i] = true;
			fu[i] = true;
		}

		traceback(0);

		delete[] colIndex;
		delete[] colIsFree;
		delete[] zhu;
		delete[] fu;
		return ans;
	}
};