class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (-- n) { // n - 1 次
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};