class Solution {
public:
    // 二维前缀和
    vector<vector<int>> s;

    // 计算子矩阵的和
    inline int get(int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }

    int maxSumSubmatrix(vector<vector<int>>& w, int K) {
        int n = w.size(), m = w[0].size();
        // 计算一下二维前缀和
        s = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + w[i - 1][j - 1];
        
        // 最大矩形和
        int res = INT_MIN;
        // 枚举两列
        for (int i = 1; i <= m; i ++ )
            for (int j = i; j <= m; j ++ ) {
                // 用来存一维前缀和的set
                set<int> S;
                S.insert(0); // s[0]
                // 枚举下边界
                for (int k = 1; k <= n; k ++ ) {
                    // 计算一下s[i]，左上角是(1, i)，右下角是(k, j)
                    int si = get(1, i, k, j);
                    auto it = S.lower_bound(si - K); // 要找 >= si - K 的最小值
                    // 如果这个值存在的化，就更新一下答案要找的最大矩形和
                    if (it != S.end()) res = max(res, si - *it);
                    // 每次计算出来的前缀和要插入到set里
                    S.insert(si);
                }
            }

            return res;
    }
};