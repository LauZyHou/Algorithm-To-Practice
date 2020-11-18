class Solution {
public:
    vector<vector<char>> g;
    int res = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        for (int i = 0; i < g.size(); i ++ )
            for (int j = 0; j < g[i].size(); j ++ )
                if (g[i][j] == '1')
                    dfs(i, j), res ++;
        return res;
    }

    void dfs(int x, int y) {
        g[x][y] = '0';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < g.size() && b >=0 && b < g[a].size() && g[a][b] == '1')
                dfs(a, b);
        }
    }
};
