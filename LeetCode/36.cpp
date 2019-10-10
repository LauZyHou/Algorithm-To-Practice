class Solution {
public:
	void mem0(int* x,int n=10) {
		for(int i=0;i<n;i++)
			x[i] = 0;
	}

    bool isValidSudoku(vector<vector<char>>& vv) {
		int use[10];
		mem0(use);
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				if(vv[i][j]=='.')
					continue;
				use[vv[i][j]-'0']++;
				if(use[vv[i][j]-'0']==2)
					return false;
			}
			mem0(use);
		}
		for(int j=0;j<9;j++) {
			for(int i=0;i<9;i++) {
				if(vv[i][j]=='.')
					continue;
				use[vv[i][j]-'0']++;
				if(use[vv[i][j]-'0']==2)
					return false;
			}
			mem0(use);
		}
		int x[8] = {-1,-1,0,1,1,1,0,-1};
		int y[8] = {0,1,1,1,0,-1,-1,-1};
		for(int i=1;i<=7;i+=3) {
			for(int j=1;j<=7;j+=3) {
				if(vv[i][j]!='.')
					use[vv[i][j]-'0']++;
				for(int k=0;k<8;k++) {
					char c = vv[i+x[k]][j+y[k]];
					if(c=='.')
						continue;
					use[c-'0']++;
					if(use[c-'0']==2)
						return false;
				}
				mem0(use);
			}
		}
		return true;
    }
};