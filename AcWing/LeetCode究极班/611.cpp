class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i ++ )
            for (int j = i - 1, k = 0; j > k; j -- ) {
                // 只要k不满足要求，就一直向右移动
                while (k < j && nums[k] + nums[j] <= nums[i]) k ++ ;
                // 区间[k, j - 1]之间的元素个数就是所求
                res += j - k;
            }
        return res;
    }
};