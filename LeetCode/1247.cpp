class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n) return -1;
        int xy = 0, yx = 0;
        for (int i = 0; i < n; i ++ ) {
            if (s1[i] == 'x' && s2[i] == 'y') xy ++ ;
            else if (s1[i] == 'y' && s2[i] == 'x') yx ++ ;
        }
        if ((xy + yx) & 1) return -1;
        // 要么全奇数要么全偶数
        return xy / 2 + yx / 2 + ((xy & 1) ? 2 : 0);
    }
};