class Solution {
public:
    int minimumDeletions(string s) {
        // f[i]：全a的最小删除次数
        // g[i]：有a有b（可以没有）的最小删除次数
        int n = s.size();
        s = ' ' + s;
        vector<int> f(n + 1), g(n + 1);
        int b = 0;
        if (s[1] == 'b')
            b = 1;
        f[1] = b, g[1] = 0;
        for (int i = 2; i <= n; i ++ ) {
            if (s[i] == 'b') {
                b ++;
                g[i] = g[i - 1];
            }
            else {
                g[i] = f[i - 1] == g[i - 1] ? g[i - 1] : (g[i - 1] + 1);
            }
            f[i] = b;
        }
        return g[n];
    }
};