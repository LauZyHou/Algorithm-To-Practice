class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, fi = 0; i < nums.size(); i ++) {
            fi = max(nums[i], nums[i] + fi);
            res = max(res, fi);
        }
        return res;
    }
};