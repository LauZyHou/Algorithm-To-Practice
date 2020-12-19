class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (auto& p: accounts) {
            int t = 0;
            for (int v: p) {
                t += v;
            }
            res = max(res, t);
        }
        return res;
    }
};