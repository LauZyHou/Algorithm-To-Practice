class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ ) {
                if (A[i - 1] == B[j - 1]) { // 状态数组里下标从1开始
                    f[i][j] = f[i - 1][j - 1] + 1;
                    res = max(res, f[i][j]);
                }
            }
        }
        return res;
    }
};