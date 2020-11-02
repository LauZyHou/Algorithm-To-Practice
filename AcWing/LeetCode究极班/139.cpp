class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        typedef unsigned long long ULL;
        const int P = 133;
        // 计算字符串哈希
        unordered_set<ULL> hash;
        for (auto& word: wordDict) {
            // 秦九韶算法求多项式
            ULL h = 0;
            for (char c: word)
                h = h * P + c;
            hash.insert(h);
        }
        
        int n = s.size();
        vector<bool> f(n + 1);
        f[0] = true;
        s = ' ' + s;
        // 前面一段是f[i]，最后一段是i+1..j
        for (int i = 0; i < n; i ++ ) {
            if (f[i]) { // 如果从1..i是有划分方法的，再去看f[i]为真会导致哪些f[j]为真
                ULL h = 0;
                for (int j = i + 1; j <= n; j ++ ) {
                    h = h * P + s[j];
                    if (hash.count(h))
                        f[j] = true;
                }
            }
        }

        return f[n];
    }
};