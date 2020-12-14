class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n);
        s[0] = nums[0];
        for (int i = 1; i < n; i ++ ) {
            s[i] = nums[i] + s[i - 1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i ++ ) {
            if (i > 0)
                res[i] += i * nums[i] - s[i - 1];
            if (i < n - 1)
                res[i] += s[n - 1] - s[i] - nums[i] * (n - i - 1);
        }
        return res;
    }
};