class Solution {
public:
    const int mod = 1337;

    // 快速幂能够在logb的时间复杂度下求出a的b次方模p的值
    int qmi(int a, int b, int p) {
        a %= p;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }

    
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        // 找到当前b的最低位
        int k = b.back();
        b.pop_back();
        return qmi(superPow(a, b), 10, mod) * qmi(a, k, mod) % mod;
    }
};