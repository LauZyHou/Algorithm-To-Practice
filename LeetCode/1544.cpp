class Solution {
public:
    string makeGood(string s) {
        string res;
        for (auto c: s) {
            if (res.size() && res.back() != c && tolower(res.back()) == tolower(c))
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};