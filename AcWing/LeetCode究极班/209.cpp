class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 双指针
        int res = INT_MAX;
        int sum = 0;
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            sum += nums[i];
            while (sum - nums[j] >= s) {
                sum -= nums[j];
                j ++;
            }
            if (sum >= s)
                res = min(res, i - j + 1);
        }
        if (res == INT_MAX) res = 0;
        return res;
    }
};