class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        for (int i = 1; i <= n; i ++) res += i + '0';
        for (int i = 0; i < k - 1; i ++)
            next_permutation(res.begin(), res.end());
        return res;
    }
};