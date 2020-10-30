class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i ++ ) {
            f[i][0] = f[i][i] = 1;
            for (int j = 1; j < i; j ++ )
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
        return f[n];
    }
};