class Solution {
public:
    string reorderSpaces(string text) {
        int i = 0, n = text.size();
        int sp = 0, wd = 0;
        
        typedef pair<int, int> PII;
        vector<PII> loc; // 单词位置

        while (i < n) {
            if (text[i] == ' ') {
                while (i < n && text[i] == ' ') i ++ , sp ++ ;
            }
            else {
                wd ++ ;
                int t = i;
                while (i < n && text[i] != ' ') i ++ ;
                loc.push_back({t, i - t});
            }
        }
        
        if (!sp || !wd) return text;

        string res = text.substr(loc[0].first, loc[0].second);
        if (wd == 1) {
            for (int i = 0; i < sp; i ++ )
                res += ' ';
            return res;
        }
        for (int i = 1; i < wd; i ++ ) {
            auto p = loc[i];
            for (int i = 0; i < sp / (wd - 1); i ++ ) res += ' ';
            res += text.substr(p.first, p.second);
        }
        for (int i = 0; i < sp % (wd - 1); i ++ ) res += ' ';
        return res;
    }
};