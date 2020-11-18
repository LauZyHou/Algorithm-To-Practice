// 区分一下第一个数选和不选两种情况

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];

        vector<int> f(n + 1), g(n + 1); // f[i]表示从1..i，i一定选的情况；g[i]表示从1..i，i一定不选的情况

        int res;

        // 第一个数不选的情况，则f[1]是不合法状态
        f[1] = INT_MIN, g[1] = 0;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        res = max(f[n], g[n]);

        // 第一个数选的情况，则g[1]是不合法状态
        f[1] = nums[0], g[1] = INT_MIN;
        for (int i = 2; i <= n; i ++ ) {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        res = max(res, g[n]);

        return res;
    }
};