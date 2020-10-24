class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        long long res = 0;
        int y = x; // x会变所以存一下
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == y;
    }
};