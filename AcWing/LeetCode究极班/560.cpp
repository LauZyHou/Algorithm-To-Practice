class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + nums[i - 1];
        unordered_map<int, int> cnt;
        cnt[k] ++ ;
        int res = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (cnt.count(s[i]))
                res += cnt[s[i]];
            cnt[s[i] + k] ++ ;
        }
        return res;
    }
};