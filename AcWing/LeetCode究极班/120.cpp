class Solution {
public:
    int minimumTotal(vector<vector<int>>& g) {
        if (g.empty() || g[0].empty()) return 0;
        for (int i = g.size() - 2; i >= 0; i -- )
            for (int j = 0; j <= i; j ++ )
                g[i][j] += min(g[i + 1][j], g[i + 1][j + 1]);
        return g[0][0];
    }
};