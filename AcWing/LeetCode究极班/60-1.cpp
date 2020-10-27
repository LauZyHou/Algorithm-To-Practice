class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> st(10); // 每个数有没有填写过

        // 每次填一个数，这个数填好后剩下的位置排列有f!种
        for (int f = n - 1; f >= 0; f --) {
            // 求f!
            int fact = 1;
            for (int i = 1; i <= f; i ++)
                fact *= i;
            
            // 枚举每个没有被使用的数
            for (int i = 1; i <= n; i ++) {
                if (st[i]) continue;
                // 如果k还是比阶乘大，就减掉往下
                if (k > fact) {
                    k -= fact;
                }
                // 否则，就填这个数，记录被使用了
                else {
                    res += i + '0';
                    st[i] = true;
                    break;
                }
            }
        }

        return res;
    }
};