class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // 枚举i，然后j和k双指针，保证i < j < k
        for (int i = 0; i < nums.size(); i ++) {
            // 防止重复，如果和上一轮的一样就跳过
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1, k = nums.size() - 1; j < k; j ++) {
                // 如果j和上一轮的一样也跳过
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // 找到满足三个数相加大于等于0的最小的k
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0)
                    k --;
                // 如果相加是0就记录
                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};