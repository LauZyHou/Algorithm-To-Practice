class Solution {
public:
    int n, m;
    vector<vector<int>> w;
    vector<vector<int>> st; // 表示状态

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        w = matrix;
        if (w.empty() || w[0].empty()) return {};
        n = w.size(), m = w[0].size();
        st = vector<vector<int>>(n, vector<int>(m, 0));

        // 枚举太平洋能到达的，也就是从左侧或者上侧的格子出发
        for (int i = 0; i < n; i ++ ) dfs(i, 0, 1); // 位置[i, 0]，1表示枚举的是太平洋0001
        for (int j = 0; j < m; j ++ ) dfs(0, j, 1);
        // 枚举大西洋能到达的，也就是从右侧或者上侧的格子出发
        for (int i = 0; i < n; i ++ ) dfs(i, m - 1, 2); // 2表示枚举的是大西洋0010
        for (int j = 0; j < m; j ++ ) dfs(n - 1, j, 2);

        // 记录答案
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (st[i][j] == 3) // 000...011
                    res.push_back({i, j});
        return res;
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void dfs(int x, int y, int t) {
        if (st[x][y] & t) // 当前格子这一位如果已经是1了，那么说明已经遍历过了
            return ;
        st[x][y] |= t;
        for (int i = 0; i < 4; i ++ ) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a >= 0 && a < n && b >= 0 && b < m && w[a][b] >= w[x][y])
                dfs(a, b, t);
        }
    }
};