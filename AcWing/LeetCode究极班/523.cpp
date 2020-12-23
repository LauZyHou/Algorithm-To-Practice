class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 如果k是0的话要特判一下是不是存在长度大于等于2的连续0
        if (!k) {
            for (int i = 1; i < nums.size(); i ++ )
                if (nums[i] == nums[i - 1] && !nums[i])
                    return true;
            return false;
        }
        int n = nums.size();
        // 处理前缀和
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + nums[i - 1];
        // 哈希表存一下从s[1]到s[i-2]每个数模k的余数
        unordered_set<int> hash;
        for (int i = 2; i <= n; i ++ ) {
            hash.insert(s[i - 2] % k);
            if (hash.count(s[i] % k))
                return true;
        }
        return false;
    }
};