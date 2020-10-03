class Solution {
public:
    bool check(int x, int m, int n, int k) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(x/i, n);
        }
        return cnt >= k;
    }

    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        while (l < r) {
            int mid = l+r >> 1;
            if (check(mid, m, n, k)) // 不超过它的数>=k个
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};