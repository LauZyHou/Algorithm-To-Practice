class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ssin(s);
        int res = 0;
        string word;
        while (ssin >> word)
            res = word.size();
        return res;
    }
};