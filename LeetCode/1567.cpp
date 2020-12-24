class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> f(n), g(n);
        f[0] = nums[0] > 0 ? 1 : 0;
        g[0] = nums[0] < 0 ? 1 : 0;
        int res = f[0];
        for (int i = 1; i < n; i ++ ) {
            if (nums[i] > 0) {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] != 0 ? g[i - 1] + 1 : 0;
            }
            else if (nums[i] < 0) {
                f[i] = g[i - 1] != 0 ? g[i - 1] + 1 : 0;
                g[i] = f[i - 1] + 1;
            }
            else {
                f[i] = g[i] = 0;
            }
            res = max(res, f[i]);
        }
        return res;
    }
};