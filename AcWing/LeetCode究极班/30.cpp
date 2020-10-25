class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res; // 结果：存所有合法的起始位置
        if (words.empty()) // 如果没有单词就直接返回
            return res;
        int n = s.size(), m = words.size(), w = words[0].size();

        // 记录word里每个单词出现的次数，用来和后面每次滑动窗口里的单词比较
        unordered_map<string, int> tot;
        for (auto &word : words)
            tot[word] ++;

        // 枚举模w为0一直到模w为w-1的所有起始位置
        for (int i = 0; i < w; i ++) {
            // 接下来要在这n/w个小段上做m大小的滑动窗口，记录窗口中每个字符串出现次数
            unordered_map<string, int> wd;
            int cnt = 0; // 记录wd中的单词在tot中出现了几次，用于快速判断wd和tot是不是相等
            // 滑动，窗口是[j..j+w-1]，要在n的范围内，每次滑动的大小是w
            for (int j = i; j + w - 1 < n; j += w) {
                // 如果窗口里已经有m个元素了，那么接下来就一直要加一个新的删一个旧的，不然就只要加就行了
                // 所以这里是考虑删掉旧的
                if (j >= i + m * w) {
                    // 窗口里最前面的一个单词
                    auto word = s.substr(j - m * w, w);
                    // 从wd里删掉，如果删掉的是tot里存在的单词且真的变少了，cnt就记录一下减少了
                    wd[word] --;
                    if (wd[word] < tot[word])
                        cnt --;
                }
                // 这里是考虑添加新的，从j开始的长w的单词
                auto word = s.substr(j, w);
                wd[word] ++;
                // 如果加了之后还没超过tot里的数量，说明确实影响了“在tot里出现的次数”
                if (wd[word] <= tot[word])
                    cnt ++;

                // 每次滑动结束后，要比较一下wd和tot是不是完全一样了，这里是比较cnt是不是已经是word里所有单词那么多了
                if (cnt == m)
                    res.emplace_back(j - (m - 1) * w); // 因为从j开始是最后一个长w的单词，所以起始位置从这里往前减m-1个w
            }
        }

        return res;
    }
};