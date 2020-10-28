class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < 1 << n; i ++) { // 1 ~ 2^n - 1
            vector<int> path;
            for (int j = 0; j < n; j ++) { // n位二进制的每一位
                if (i >> j & 1)
                    path.emplace_back(nums[j]);
            }
            res.emplace_back(path);
        }
        return res;
    }
};