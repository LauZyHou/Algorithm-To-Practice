class Solution {
public:
    int strongPasswordChecker(string s) {
        // a: 数字数量，b：小写字母数量，c：大写字母数量
        int a = 0, b = 0, c = 0;
        // n：长度，k：字符种类数（强密码要求包含小写、大写、数字）
        int n = s.size(), k = 0;
        for (auto x: s) {
            if (x >= '0' && x <= '9') a = 1;
            else if (x >= 'a' && x <= 'z') b = 1;
            else if (x >= 'A' && x <= 'Z') c = 1;
        }
        k = a + b + c;
        if (n < 6) return max(6 - n, 3 - k);
        else {
            // p：要修改的次数，del：要删除的次数，res：答案要求的操作次数
            int p = 0, del = n - 20, res = del;
            // 求一下所有的连续段
            int d[3] = {0, 0, 0}; // 模3余0/1/2的连续段的数量
            for (int i = 0; i < s.size(); i ++ ) {
                int j = i;
                while (j < s.size() && s[j] == s[i]) j ++ ;
                // 当前连续段的长度
                int r = j - i;

                p += r / 3;
                // 如果过长，记录到它模3余下几的那一类去
                if (r >= 3) d[r % 3] ++ ;

                // 双指针更新i
                i = j - 1;
            }
            // 如果不超过20，就是只考虑修改和种类
            if (n <= 20) return max(p, 3 - k);
            // 否则，就是要考虑删除，从d[0]开始考虑
            if (d[0] && del > 0) {
                int t = min(d[0], del);
                del -= t;
                p -= t;
            }
            if (d[1] && del > 0) {
                int t = min(d[1] * 2, del);
                del -= t;
                p -= t / 2;
            }
            // 剩下的p都是余2的情况
            if (p && del > 0) {
                int t = min(p * 3,  del);
                p -= t / 3;
            }
            // 一定要删除的，加上考虑修改和种类的情况
            return res + max(p, 3 - k);
        }
    }
};