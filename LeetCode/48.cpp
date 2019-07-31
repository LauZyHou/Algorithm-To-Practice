class Solution {
public:
    void rotate(vector<vector<int>>& vv) {
		//只要是对称操作都只需要固定的空间
		//先转置再左右翻转每行
        int len = vv.size();
		for(int i=0;i<len;i++)
			for(int j=i+1;j<len;j++) {
				int t = vv[i][j];
				vv[i][j] = vv[j][i];
				vv[j][i] = t;
			}
		for(int i=0;i<len;i++)
			for(int j=0;j<len/2;j++) {
				int t = vv[i][j];
				vv[i][j] = vv[i][len-1-j];
				vv[i][len-1-j] = t;
			}
    }
};