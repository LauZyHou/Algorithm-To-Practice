class Solution {
private:
    int dp[100][100][100];
    int calDP(vector<int> &v, int l, int r, int k) {
        if (l > r)
            return 0;
        if (dp[l][r][k])
            return dp[l][r][k];
        dp[l][r][k] = calDP(v, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i ++) {
            if (v[i] == v[r]) {
                dp[l][r][k] = max(dp[l][r][k], calDP(v, l, i, k + 1) + calDP(v, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }

public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        return calDP(boxes, 0, boxes.size() - 1, 0);
    }
};