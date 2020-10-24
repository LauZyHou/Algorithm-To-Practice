class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 还是和第15题一样，用双指针找到ni + nj + nk >= target最小的k
        // 那么ni + nj + n(k-1) 就是小于target最大的k
        sort(nums.begin(), nums.end());
        pair<int, int> res({INT_MAX, INT_MAX}); // <三数和与target差值绝对值，三数和>
        for (int i = 0; i < nums.size() - 2; i ++) {
            for (int j = i + 1, k = nums.size() - 1; j < k; j ++) {
                // >= target的最小k
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target)
                    k --;
                int sum = nums[i] + nums[j] + nums[k];
                res = min(res, make_pair(abs(sum - target), sum)); // 这里sum不一定是>=target的，所以要abs
                // <target的最大k就是k-1
                if (k - 1 > j) {
                    sum = nums[i] + nums[j] + nums[k - 1];
                    res = min(res, make_pair(target - sum, sum)); // 这里用k-1的一定是<target的，不用abs
                }
            }
        }
        return res.second;
    }
};