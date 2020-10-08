class Solution {
private:
    int ans;
    void check(int val, vector<string>& w, vector<char>& lt, vector<int>& s, vector<int> &ltUse) {
        // 计算每个单词用多少次
        vector<int> realUse(26, 0);
        for (int i = 0; i < w.size(); i ++) {
            if (!(val & (1 << i)))
                continue;
            string& s = w[i];
            for (char c : s) {
                realUse[c - 'a'] ++;
            }
        }
        // 比较结果
        int res = 0;
        for (int i = 0; i < 26; i ++) {
            if (realUse[i] > ltUse[i])
                return ;
            res += s[i] * realUse[i];
        }
        if (res > ans)
            ans = res;
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ans = 0;

        auto &w = words;
        auto &lt = letters;
        auto &s = score;

        int wlen = w.size();
        
        vector<int> ltUse(26, 0);
        for (char c : lt)
            ltUse[c - 'a'] ++;
        
        for (int i = 0; i < (1 << wlen); i ++) {
            check(i, w, lt, s, ltUse);
        }
        return ans;
    }
};