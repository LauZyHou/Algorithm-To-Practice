class Solution {
public:
    int n, m;
    vector<vector<char>> board;

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    void solve(vector<vector<char>>& _board) {
        board = _board;
        n = board.size();
        if (!n) return ;
        m = board[0].size();
        if (!m) return ;

        for (int i = 0; i < n; i ++ ) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][m - 1] == 'O') dfs(i, m - 1);
        }

        for (int j = 0; j < m; j ++ ){
            if (board[0][j] == 'O') dfs(0, j);
            if (board[n - 1][j] == 'O') dfs(n - 1, j);
        }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (board[i][j] == '#')
                    _board[i][j] = 'O';
                else
                    _board[i][j] = 'X';
    }

    void dfs(int x, int y) {
        board[x][y] = '#';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (board[a][b] == 'O')
                dfs(a, b);
        }
    }
};