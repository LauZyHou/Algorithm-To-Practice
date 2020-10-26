class Solution {
public:
    // 记录每一行、每一列、每一个小方格里每个数有没有使用过
    bool row[9][9], col[9][9], cell[3][3][9];

    void solveSudoku(vector<vector<char>>& board) {
        // 清空记录
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(cell, 0, sizeof cell);

        // 记录已经填写的数据
        for (int i = 0; i < 9; i ++)
            for (int j = 0; j < 9; j ++)
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                }
        
        dfs(board, 0, 0); // 从左上角开始一行一行填写
    }

    bool dfs(vector<vector<char>>& g, int x, int y) {
        // 如果一行填完就去下一行
        if (y == 9) x ++, y = 0;
        // 如果已经全填完就返回true
        if (x == 9) return true;

        // 如果这里已经有数了，就填下一个
        if (g[x][y] !='.')
            return dfs(g, x, y + 1);
        // 否则，尝试填写数，这里是将'1'~'9;映射到了0~8上
        for (int t = 0; t < 9; t ++) {
            // 判断没有被使用
            if (row[x][t] || col[y][t] || cell[x / 3][y / 3][t])
                continue;
            // 写上这个数，然后继续搜
            g[x][y] = t + '1';
            row[x][t] = col[y][t] = cell[x / 3][y / 3][t] = true;
            if (dfs(g, x, y + 1))
                return true;
            // 恢复现场
            g[x][y] = '.';
            row[x][t] = col[y][t] = cell[x / 3][y / 3][t] = false;
        }

        return false; // 找不到
    }
};