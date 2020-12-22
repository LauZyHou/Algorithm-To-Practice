class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        // 区间dp，遍历区间长度
        for (int len = 1; len <= n; len ++ ) {
            // 遍历左端点
            for (int i = 0; i + len - 1 < n; i ++ ) {
                // 右端点
                int j = i + len - 1;
                if (len == 1) f[i][j] = nums[i];
                else {
                    f[i][j] = max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1] >= 0;
    }
};