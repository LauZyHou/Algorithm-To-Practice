class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return "";
        if (n == 1) return to_string(nums[0]);
        if (n == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
        // 否则，在第二个数和最后一个数之两侧加括号
        string res = to_string(nums[0]) + "/(";
        for (int i = 1; i < n; i ++ )
            res += to_string(nums[i]) + '/';
        res[res.size() - 1] = ')';
        return res;
    }
};