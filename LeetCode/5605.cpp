class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a1 = "", a2 = "";
        for (auto& s: word1)
            a1 += s;
        for (auto& s: word2)
            a2 += s;
        return a1 == a2;
    }
};