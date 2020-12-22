class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (auto x: nums)
            res += abs(x - nums[n / 2]);
        return res;
    }
};