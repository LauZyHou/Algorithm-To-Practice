typedef long long LL;

class Solution {
public:
    LL integerReplacement(LL n) {
        if (n == 1) return 0;
        if (n & 1) return min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
        return integerReplacement(n >> 1) + 1;
    }
};