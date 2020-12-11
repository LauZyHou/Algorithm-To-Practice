class Solution {
public:
    int numSquares(int n) {
        // 4^a * (8b + 7)
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        int a = 0;
        while (a * a <= n) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n)
                return !!a + !!b;
            a ++ ;
        }
        return 3;
    }
};