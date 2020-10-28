class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int n : nums)
            if (n == target)
                return true;
        return false;
    }
};