class Solution {
public:
    void setZeroes(vector<vector<int>>& g) {
        if (g.empty() || g[0].empty()) return ;
        int n = g.size(), m = g[0].size();
        
        int r0 = 1, c0 = 1; // 1表示没有0，0表示有0
        for (int j = 0; j < m; j ++) if (!g[0][j]) r0 = 0;
        for (int i = 0; i < n; i ++) if (!g[i][0]) c0 = 0;

        // 除了第0列之外的所有列，记到第0行
        for (int j = 1; j < m; j ++)
            for (int i = 0; i < n; i ++)
                if (!g[i][j])
                    g[0][j] = 0;
        
        // 除了第0行之外的所有行，记到第0列
        for (int i = 1; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (!g[i][j])
                    g[i][0] = 0;
        
        // 扫第0行，刷1~m-1列
        for (int j = 1; j < m; j ++)
            if (!g[0][j])
                for (int i = 0; i < n; i ++)
                    g[i][j] = 0;
        
        // 扫第0列，刷第1~n-1行
        for (int i = 1; i < n; i ++)
            if (!g[i][0])
                for (int j = 0; j < m; j ++)
                    g[i][j] = 0;

        if (!r0) for (int j = 0; j < m; j ++) g[0][j] = 0;
        if (!c0) for (int i = 0; i < n; i ++) g[i][0] = 0; 
    }
};