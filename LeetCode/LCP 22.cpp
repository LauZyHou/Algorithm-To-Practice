class Solution {
public:
    int paintingPlan(int n, int k) {
        if (k == 0 || k == n * n) return 1;
        int res = 0;
        for (int i = 0; i <= n; i ++ )
            for (int j = 0; j <= n; j ++ )
                if (n * (i + j) - i * j == k)
                    res += C(n, i) * C(n, j);
        return res;
    }

    int C(int a, int b) {
        typedef long long LL;
        LL res = 1;
        for (int i = a; i > a - b; i -- ) res *= i;
        for (int i = 2; i <= b; i ++ ) res /= i;
        return (int)res;
    }
};