class Solution {
public:
    string originalDigits(string s) {
        string name[] = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
        };
        int ord[] = {0, 8, 3, 2, 6, 4, 5, 1, 7, 9};
        unordered_map<char, int> cnt;
        for (auto c: s) cnt[c] ++ ;
        string res;
        for (int x: ord) {
            // 实现的时候不用对每个单词去算那个特殊字母，直接去看每个单词是不是都有就可以了
            while (true) {
                bool havex = true;
                for (auto c: name[x])
                    if (!cnt[c]) {
                        havex = false;
                        break;
                    }
                if (!havex)
                    break;
                res += to_string(x);
                for (auto c: name[x])
                    cnt[c] -- ;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};