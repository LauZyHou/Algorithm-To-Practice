class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& str : strs) {
            string nstr = str;
            sort(nstr.begin(), nstr.end());
            hash[nstr].emplace_back(str);
        }

        vector<vector<string>> res;
        for (auto& item : hash) {
            res.emplace_back(item.second);
        }
        
        return res;
    }
};