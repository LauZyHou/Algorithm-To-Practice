class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        // 枚举每个物品
        for (auto& str: strs) {
            // 计算一下0的个数和1的个数
            int zero = 0, one = 0;
            for (auto c: str)
                if (c == '0') zero ++ ;
                else one ++ ;
            // 由于是01背包，所以从大到小枚举费用约束
            for (int i = m; i >= zero; i -- )
                for (int j = n; j >= one; j -- )
                    f[i][j] = max(f[i][j], f[i - zero][j - one] + 1);
        }
        return f[m][n];
    }
};