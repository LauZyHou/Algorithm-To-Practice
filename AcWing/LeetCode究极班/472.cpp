class Solution {
public:
    // 将所有字符串存在一个哈希表里面，用来快速判断一个字符串是否存在
    unordered_set<string> hash;

    bool check(string& word) {
        int n = word.size();
        vector<int> f(n + 1, INT_MIN); // f[i]表示前i个字符最多有由几个组成
        // 最开始定义成INT_MIN来表示是没法又其它字符串组成的
        f[0] = 0; // 空字符串能由0个单词组成
        // 由于题目卡常，要优化一下常数，这里是枚举一下i后面的长度j，然后用f[i]看看能不能更新f[i+j]这个状态
        for (int i = 0; i <= n; i ++ ) { // 用f[i]更新f[i + j]
            if (f[i] < 0) continue; // 如果f[i]都不合法就直接剪掉
            // 从大到小枚举长度
            for (int j = n - i; j; j -- ) {
                // 如果从i开始长度是j的字符串是存在的话
                if (hash.count(word.substr(i, j))) {
                    f[i + j] = max(f[i + j], f[i] + 1); // 就可以用f[i]更新f[i + j]
                    // 每次更新完立即判断f[n]，这也是一个剪枝
                    if (f[n] > 1) return true;
                }
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto& w: words) hash.insert(w);
        vector<string> res;
        // 枚举处理每个单词
        for (auto& w: words)
            if (check(w))
                res.push_back(w);
        return res;
    }
};