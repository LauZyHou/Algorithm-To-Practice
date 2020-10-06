class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& m) {
        vector<int> ans; // best _x1, _y1, _x2, _y2
        for (int i = 0; i < 4; i ++) ans.push_back(0);
        int R = m.size();
        if (!R) return ans;
        int C = m[0].size();
        if (!C) return ans;

        int dp;
        int maxval = INT_MIN;
        int _x1, _y1;

        vector<int> s(C);
        for (int r1 = 0; r1 < R; r1 ++) {
            for (int c = 0; c < C; c ++)
                s[c] = 0;
            _x1 = r1, _y1 = 0;
            for (int r2 = r1; r2 < R; r2 ++) {
                dp = 0; // 每次重新做动态规划
                for (int c = 0; c < C; c ++) {
                    s[c] += m[r2][c];
                    if (dp > 0)
                        dp += s[c];
                    else {
                        dp = s[c];
                        _y1 = c;
                    }
                    if (dp > maxval) {
                        maxval = dp;
                        ans[0] = _x1;
                        ans[1] = _y1;
                        ans[2] = r2;
                        ans[3] = c;
                    }
                }
            }
        }

        return ans;
    }
};