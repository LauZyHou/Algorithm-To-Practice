class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n);
		for(int i=0;i<n;i++)
			ans[i] = vector<int>(n);
		int nowNum = 1;//当前正在填充的数字
		int rowBegin = 0;
		int rowEnd = n-1;
		int colBegin = 0;
		int colEnd = n-1;
		int nn = n*n;
		//只要没填充完就一直填充
		while(nowNum<=nn) {
			//从左往右,行不变,列依次加1
			for(int j=colBegin;j<=colEnd;j++)
				ans[rowBegin][j] = nowNum++;
			//因为最上边的行都走完了,接下来起始行要加1
			rowBegin += 1;
			
			//从上往下,列不变,行依次加1
			for(int i=rowBegin;i<=rowEnd;i++)
				ans[i][colEnd] = nowNum++;
			//因为最右边的行都走完了,接下来终止列要减1
			colEnd -= 1;

			//从右往左,行不变,列依次减1
			for(int j=colEnd;j>=colBegin;j--)
				ans[rowEnd][j] = nowNum++;
			//因为最下面的行都走完了,接下来终止行要减1
			rowEnd -= 1;

			//从下往上,列不变,行依次减1
			for(int i=rowEnd;i>=rowBegin;i--)
				ans[i][colBegin] = nowNum++;
			//因为最左边的列都走完了,接下来起始列要加1
			colBegin +=1;
		}
		return ans;
    }
};