class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;
        for (auto x : nums)
            S.insert(x);
        
        int res = 0;

        for (auto x : nums) {
            if (S.count(x) && !S.count(x - 1)) {
                S.erase(x);
                int y = x + 1;
                while (S.count(y)) {
                    S.erase(y);
                    y ++;
                }
                res = max(res, y - x);
            }
        }

        return res;
    }
};