class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 1);
        int _min = INT_MAX;
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
            _min = min(_min, s[i]);
        }
        return max(1, 1 - _min);
    }
};