class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
        
        for (int j = 1; j <= n; j ++ )
            for (int i = 1; i <= j; i ++ ) {
                if (i == j)
                    g[i][j] = true;
                else if (s[i] == s[j]) {
                    g[i][j] = i + 1 == j || g[i + 1][j - 1];
                }
            }
        
        vector<int> f(n + 1, 1e8);
        f[0] = -1;
        for (int i = 1; i <= n; i ++ ) {
            for (int k = 1; k <= i; k ++ ) {
                if (g[k][i]) {
                    f[i] = min(f[i], f[k - 1] + 1);
                }
            }
        }

        return f[n];
    }
};