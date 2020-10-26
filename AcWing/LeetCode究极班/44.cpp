class Solution {
public:
    bool isMatch(string s, string p) {
        // f[i,j]表示s[1~i]和p[1~j]是否匹配
        // f[i,j]可以看p[j]是不是'*'来分别讨论
        // 当p[j]不是'*'，直接看s[i]匹配p[j] && f[i-1,j-1]
        // 当p[j]是'*'时，要枚举一下它能匹配多少字符
        // 匹配0个字符时，只要看f[i,j-1]
        // 匹配1个字符时，看f[i-1,j-1]
        // 匹配2个字符时，看f[i-2,j-1]
        // 直到f[0,j]，这样总的时间复杂度是O(n^3)
        
        // 优化一下，看f[i-1,j]这个状态
        // 它在p[j]是'*'时是f[i-1,j-1] || f[i-2,j-1] || f[i-3,j-1] || ... || f[0,j-1]
        // 所以f[i,j]在p[j]是'*'时只要取f[i,j-1] || f[i-1,j-1]
        // 这样总的时间复杂度时O(n^2)
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p; // 下标从1开始
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;

        // f[0,j]是可能为true的，f[i>0][0]则一定是false
        for (int i = 0; i <= n; i ++)
            for (int j = 1; j <= m; j ++) {
                if (p[j] == '*') {
                    f[i][j] = f[i][j - 1] || i && f[i - 1][j];
                }
                else {
                    f[i][j] = (s[i] == p[j] || p[j] == '?') && i && f[i - 1][j - 1];
                }
            }
        
        return f[n][m];
    }
};