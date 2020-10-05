typedef long long LL;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1e9 + 7;
        int lcm = a / __gcd(a, b) * b;
        LL l = 0, r = 1e15;
        while (l < r) {
            LL mid = l+r >> 1;
            if (mid / a + mid / b - mid / lcm >= n)
                r = mid;
            else
                l = mid + 1;
        }
        return l % mod;
    }
};