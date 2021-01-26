class Solution {
public:
    int largestPalindrome(int n) {
        typedef long long LL;
        if (n == 1) return 9; // 3 * 3 == 9
        // 先找到n位数的最大值
        int maxv = pow(10, n) - 1;
        // 从最大值开始枚举
        for (int i = maxv; ; i -- ) {
            auto a = to_string(i); // 前一半
            auto b = a;
            reverse(b.begin(), b.end()); // 后一半
            auto num = stoll(a + b);
            // 从最大值开始枚举
            for (LL j = maxv; j * j >= num; j -- )
                if (num % j == 0) // 找到了两个n位数相乘是回文数
                    return num % 1337;
        }
        return 0; // 不会执行
    }
};