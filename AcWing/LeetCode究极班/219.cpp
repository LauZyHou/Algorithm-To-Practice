class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i ++ ) {
            int x = nums[i];
            if (hash.count(x) && i - hash[x] <= k)
                return true;
            hash[x] = i;
        }
        return false;
    }
};