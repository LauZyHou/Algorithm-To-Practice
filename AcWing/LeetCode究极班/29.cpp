class Solution {
public:
    int divide(int x, int y) {
        typedef long long LL;
        vector<LL> exp;
        bool is_minus = false;
        if (x < 0 && y > 0 || x > 0 && y < 0)
            is_minus = true;

        LL a = abs((LL)x), b = abs((LL)y); // 求a / b
        for (LL i = b; i <= a; i = i + i)
            exp.emplace_back(i); // 2^0 * b, 2^1 * b, ...
        
        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; i --) {
            if (a >= exp[i]) { // a >= 2^i * b
                res += 1ll << i; // 防溢出
                a -= exp[i]; // 把2^i * b从a里减去
            }
        }
        
        if (is_minus)
            res = -res;
        
        // 判断有没有超出int范围
        if (res < INT_MIN || res > INT_MAX)
            return INT_MAX;
        return res;
    }
};