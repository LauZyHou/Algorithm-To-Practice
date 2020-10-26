class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[10];

        // 判断每行
        for (int i = 0; i < 9; i ++) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.')
                    continue;
                int a = board[i][j] - '0';
                if (st[a])
                    return false;
                st[a] = true;
            }
        }

        // 判断每列
        for (int j = 0; j < 9; j ++) {
            memset(st, 0, sizeof st);
            for (int i = 0; i < 9; i ++) {
                if (board[i][j] == '.')
                    continue;
                int a = board[i][j] - '0';
                if (st[a])
                    return false;
                st[a] = true;
            }
        }

        // 判断每个小方格
        for (int dx = 0; dx < 9; dx += 3) {
            for (int dy = 0; dy < 9; dy += 3) {
                memset(st, 0, sizeof st);
                for (int i = 0; i < 3; i ++) {
                    for (int j = 0; j < 3; j ++) {
                        if (board[dx + i][dy + j] == '.')
                            continue;
                        int a = board[dx + i][dy + j] - '0';
                        if (st[a])
                            return false;
                        st[a] = true;
                    }
                }
            }
        }

        return true;
    }
};