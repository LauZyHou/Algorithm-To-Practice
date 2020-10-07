class Solution {
private:
    int ans;
    void traceback(int row, int n, vector<bool> &colUse, vector<bool> &mainDiag, vector<bool> &subDiag) {
        if (row == n) {
            ans ++;
            return ;
        }
        // 要在这行放置，遍历每一列
        for (int col = 0; col < n; col ++) {
            if (colUse[col] || mainDiag[row - col + n] || subDiag[row + col])
                continue;
            else {
                colUse[col] = mainDiag[row - col + n] = subDiag[row + col] = true;
                traceback(row + 1, n, colUse, mainDiag, subDiag);
                colUse[col] = mainDiag[row - col + n] = subDiag[row + col] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        ans = 0;
        vector<bool> colUse(n, false); // 列被使用
        vector<bool> mainDiag(n * 2, false); // 主对角线被使用
        vector<bool> subDiag(n * 2, false); // 副对角线被使用
        traceback(0, n, colUse, mainDiag, subDiag);
        return ans;
    }
};