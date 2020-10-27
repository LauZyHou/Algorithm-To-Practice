typedef long long LL;

class Solution {
public:
    double qmi(double a, LL k) {
        double res = 1;
        while (k) {
            if (k & 1) {
                res = res * a;
            }
            k >>= 1;
            a = a * a;
        }
        return res;
    }

    double myPow(double x, int n) {
        if (n < 0)
            return 1 / qmi(x, -(LL)n);
        return qmi(x, n);
    }
};