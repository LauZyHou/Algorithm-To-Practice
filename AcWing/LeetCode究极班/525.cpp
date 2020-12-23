class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + (nums[i - 1] ? nums[i - 1] : -1); // 0变成-1
        }
        // 因为要最长，所以这里记录一下出现的最早位置
        unordered_map<int, int> hash;
        for (int i = 1; i <= n; i ++ ) {
            if (!hash.count(s[i - 1]))
                hash[s[i - 1]] = i - 1;
            if (hash.count(s[i])) {
                res = max(res, i - hash[s[i]]);
            }
        }
        return res;
    }
};