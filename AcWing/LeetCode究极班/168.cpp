class Solution {
public:
    string convertToTitle(int n) {
        typedef long long LL;
        // 先算有多少位，正好把每一位减掉一个1
        int k = 1;
        for (LL p = 26; p < n; p = p * 26) {
            n -= p;
            k ++;
        }

        n --;
        string res;
        while (k --) {
            res += n % 26 + 'A';
            n /= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};