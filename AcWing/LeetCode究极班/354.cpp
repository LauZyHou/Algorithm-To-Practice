class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& w) {
        int n = w.size();
        sort(w.begin(), w.end());
        vector<int> f(n);
        
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            f[i] = 1;
            // 枚举每个位置前面的所有位置，看能不能作为子序列的倒数第二个元素
            for (int j = 0; j < i; j ++ ) {
                // 如果j是可以放在i前面的
                if (w[j][0] < w[i][0] && w[j][1] < w[i][1])
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        return res;
    }
};