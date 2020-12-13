class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> mp;
        for (char c: allowed)
            mp.insert(c);
        int res = words.size();
        for (auto s: words) {
            for (char c: s) {
                if (!mp.count(c)) {
                    res --;
                    break;
                }
            }
        }
        return res;
    }
};