class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        
        for (int i = 0; i <= n; i ++ )
            for (int j = 0; j <= m; j ++ ) {
                if (i == 0 && j == 0) f[i][j] = true; // 空串和空串可以拼成空串
                else {
                    if (i > 0 && s1[i] == s3[i + j]) f[i][j] = f[i - 1][j];
                    if (j > 0 && s2[j] == s3[i + j]) f[i][j] = f[i][j] || f[i][j - 1];
                }
            }
        
        return f[n][m];
    }
};