class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 两个数：直接双指针
        // 三个数：枚举一个数，然后双指针
        // 这题是四个数，枚举两个数，然后双指针，前三个数要判断和前一轮有变化
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i ++) {
            if (i && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j ++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int k = j + 1, u = nums.size() - 1; k < u; k ++) {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;
                    // 找到加和>target的最小u
                    while (u - 1> k && nums[i] + nums[j] + nums[k] + nums[u - 1] >= target)
                        u --;
                    if (nums[i] + nums[j] + nums[k] + nums[u] == target)
                        res.push_back({nums[i], nums[j], nums[k], nums[u]});
                }
            }
        }
        return res;
    }
};