class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        int n = nums.size();
        vector<long long> f(t + 1);
        f[0] = 1; // 一个数都没有的时候方案数是1
        for (int j = 0; j <= t; j ++ ) // 从小到大枚举状态j
            for (auto v: nums) // 枚举每个数
                if (j >= v) // 能放下
                    f[j] = (f[j] + f[j - v]) % INT_MAX; // 那么就加上放了一个这个数时候的所有方案
        return f[t];
    }
};