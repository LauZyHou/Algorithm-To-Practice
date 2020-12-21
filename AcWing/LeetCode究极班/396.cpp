class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        typedef long long LL;
        int n = a.size();
        LL sum = 0, cur = 0;
        // 计算一下总和和第一行的和
        for (int i = 0; i < n; i ++ ) {
            sum += a[i];
            cur += i * a[i];
        }
        LL res = cur;
        for (int i = n - 1; i >= 0; i -- ) {
            cur = cur - (LL)a[i] * n + sum;
            res = max(res, cur);
        }
        return res;
    }
};