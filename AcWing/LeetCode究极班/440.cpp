class Solution {
public:
    int f(int prefix, int n) {
        long long p = 1;
        auto A = to_string(n), B = to_string(prefix);
        // n的长度和当前前缀的长度差
        int dt = A.size() - B.size();
        int res = 0;
        // 遍历前缀后面可以放置的每个位置
        for (int i = 0; i < dt; i ++ ) {
            res += p;
            p *= 10;
        }
        // 把A变成和B一样长的那么多位，然后比较和B的字典序关系
        A = A.substr(0, B.size());
        if (A == B) res += n - prefix * p + 1;
        else if (A > B) res += p;
        return res;
    }

    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (k > 1) {
            // 计算以prefix作为前缀，在1~n里面有几个数
            int cnt = f(prefix, n);
            // 如果要找的第k个数字，这个数字是比当前前缀往后的数字数量多的
            if (k > cnt) {
                k -= cnt; // 跨过这个前缀的所有数字
                prefix ++ ; // 前缀往后一个字典序
            }
            // 如果要找的第k个数字，这个数字是不超过当前前缀往后的数字的
            else {
                k -- ; // 这是为了减掉这个前缀作为第一个数
                prefix *= 10;
            }
        }
        return prefix; // k减到0，当前前缀就是所求
    }
};