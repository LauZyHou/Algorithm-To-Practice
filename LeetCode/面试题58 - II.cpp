class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.length();
        string prefix = s.substr(n);
        string suffix = s.substr(0, n);
        return prefix + suffix;
    }
};