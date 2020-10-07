class Solution {
private:
    vector<vector<string> > ans;
    void traceback(int row, int n, vector<bool> &colUse, vector<bool> &mainDiag, vector<bool> &subDiag, vector<string> &solv) {
        if (row == n) {
            ans.push_back(solv);
            return ;
        }
        // 在这行放置
        for (int col = 0; col < n; col ++) {
            if (colUse[col] || mainDiag[row - col + n] || subDiag[row + col])
                continue;
            colUse[col] = mainDiag[row - col + n] = subDiag[row + col] = true;
            solv[row][col] = 'Q';
            traceback(row + 1, n, colUse, mainDiag, subDiag, solv);
            colUse[col] = mainDiag[row - col + n] = subDiag[row + col] = false;
            solv[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        // 回溯用的答案形式
        char ndot[n + 1];
        for (int i = 0; i < n; i ++)
            ndot[i] = '.';
        ndot[n] = '\0';
        string ndots = string(ndot);
        vector<string> solv;
        for (int i = 0; i < n; i ++)
            solv.push_back(ndots);
        // 判断工具
        vector<bool> colUse(n, false);
        vector<bool> mainDiag(2 * n, false);
        vector<bool> subDiag(2 * n, false);
        // 求解
        traceback(0, n, colUse, mainDiag, subDiag, solv);
        return ans;
    }
};