class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        for (int i = 0; i + 10 <= s.size(); i ++ )
            hash[s.substr(i, 10)] ++;
        vector<string> res;
        for (auto [_s, c]: hash)
            if (c > 1)
                res.emplace_back(_s);
        return res;
    }
};