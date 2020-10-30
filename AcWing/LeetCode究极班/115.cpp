class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        s = ' ' + s, t = ' ' + t;
        typedef long long LL;
        vector<vector<LL>> f(n + 1, vector<LL>(m + 1));
        // t为空时，s只要一个都不选就是一种方案
        // s为空t不空时，一定是0
        for (int i = 0; i <= n; i ++ )
            f[i][0] = 1;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= min(m, i); j ++ ) { // 这里可以优化j到i就结束，j>i时，s里字符都不够用
                f[i][j] = f[i - 1][j];
                if (s[i] == t[j])
                    f[i][j] += f[i - 1][j - 1];
            }
        return f[n][m];
    }
};