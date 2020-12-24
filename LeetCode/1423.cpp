class Solution {
public:
    int maxScore(vector<int>& w, int k) {
        int n = w.size();
        if (n < k) return -1;
        k = n - k;
        int res = INT_MAX;
        int allsum = 0;
        for (int i = 0, j = 0, sum = 0; i < n; i ++ ) {
            allsum += w[i];
            sum += w[i];
            if (i - j + 1 == k) {
                res = min(res, sum);
                sum -= w[j ++ ];
            }
        }
        if (k == 0) return allsum;
        return allsum - res;
    }
};