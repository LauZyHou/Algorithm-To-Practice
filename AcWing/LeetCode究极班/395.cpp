class Solution {
public:
    int k;
    // 当前区间里每个字符的出现次数
    unordered_map<char, int> cnt;

    void add(char c, int& x, int& y) {
        // 如果插入之前没有这个字符，那么插入之后就多了一种字符，所以x ++
        if (!cnt[c]) x ++ ;
        cnt[c] ++ ;
        // 如果插入这个字符使得它的数量到达k了，那么满足要求的字符就多了一个，所以y ++
        if (cnt[c] == k) y ++ ;
    }

    void del(char c, int& x, int& y) {
        // 如果删除之前它正好是k个，那么删除它就会导致满足要求的字符少了一个，所以y --
        if (cnt[c] == k) y -- ;
        cnt[c] -- ;
        // 如果删除之后这个字符就没了，那么字符种类减少1，所以x --
        if (!cnt[c]) x -- ;
    }

    int longestSubstring(string s, int _k) {
        k = _k;
        int res = 0;
        // 枚举区间里最多包含的字符数量
        for (int q = 1; q <= 26; q ++ ) {
            // 每次扫描之前要将哈希表清空
            cnt.clear();
            // i：右侧指针，j：左侧指针，x：当前区间里字符有几种，y：当前区间里满足要求的字符有几种
            for (int i = 0, j = 0, x = 0, y = 0; i < s.size(); i ++ ) {
                add(s[i], x, y); // 将s[i]加入，维护一下x和y
                // 当加入它使得不同字符数量大于q的时候，就不断去掉最开头的字符
                while (x > q) del(s[j ++ ], x, y);
                // 如果区间里所有字符都满足要求，就更新一下答案
                if (x == y) res = max(res, i - j + 1);
            }
        }
        return res;
    }
};