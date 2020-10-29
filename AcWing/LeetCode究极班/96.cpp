class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i ++ ) // 求f[i]，即长度为i的区间的方案数
            for (int k = 1; k <= i; k ++ ) // 枚举1~i的每个分割点
                f[i] += f[k - 1] * f[i - k];
        return f[n];
    }
};