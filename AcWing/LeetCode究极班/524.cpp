class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string& a, string& b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return a < b;
        });
        for (auto& a: d) {
            if (check(a, s))
                return a;
        }
        return "";
    }

    bool check(string& a, string& b) {
        int k = 0;
        for (int i = 0; i < b.size() && k < a.size(); i ++ ) {
            if (a[k] == b[i]) k ++ ;
        }
        return k == a.size();
    }
};