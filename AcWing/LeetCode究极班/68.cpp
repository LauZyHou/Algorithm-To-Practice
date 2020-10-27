class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // 1. 最后一行，左对齐
        // 2. 只包含一个单词，左对齐
        // 3. 其它情况，左右对齐
        vector<string> res;
        // i遍历每个单词，j找到这行的最后一个单词后面一个位置（也就是下一行第一个单词）
        for (int i = 0, j = i + 1; i < words.size(); i = j, j = i + 1) {
            // 模拟这行的长度，用来找这行的截至单词（后面一个单词）的下标j
            int len = words[i].size();
            // 找j，同时更新这行的长度len
            while (j < words.size() && len + 1 + words[j].size() <= maxWidth) {
                len += 1 + words[j].size();
                j ++;
            }
            // 生成这一行的字符串解line
            string line;
            // 当前是最后一行，或者只包含一个单词，都是左对齐
            if (j == words.size() || j == i + 1) {
                // 单词 ' ' 单词 ' ' 单词
                line += words[i];
                for (int k = i + 1; k < j; k ++)
                    line += ' ' + words[k];
                // 补末尾空格
                line += string(maxWidth - line.size(), ' ');
            }
            // 否则是左右对齐
            else {
                // 这行单词数量是j - i，这行的间隔数量是j - i - 1
                int cnt = j - i - 1;
                // 这行每个单词之间放一个空格后的长度是len，由此算出这行应该放的空格数
                int r = maxWidth - len + cnt;
                // 先放第一个单词
                line += words[i];
                int k = 0;
                // 对于前r % cnt个间隔，都要额外分配一个多出来的' '，即每个间隔是r / cnt + 1个空格
                while (k < r % cnt) {
                    line += string(r / cnt + 1, ' ') + words[i + k + 1];
                    k ++;
                }
                // 对于剩下的间隔，只放r / cnt个空格
                while (k < cnt) {
                    line += string(r / cnt, ' ') + words[i + k + 1];
                    k ++;
                }
            }

            // 把这一行加到结果里
            res.emplace_back(line);
        }
        
        return res;
    }
};