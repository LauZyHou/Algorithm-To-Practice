class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n = nums.size();
        if (!(n & 1))
            return true;
        int ans = 0;
        for (int nu : nums)
            ans ^= nu;
        return ans == 0;
    }
};