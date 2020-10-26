class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto x : nums)
            hash.insert(x);
        int res = 1;
        while (hash.count(res))
            res ++;
        return res;
    }
};