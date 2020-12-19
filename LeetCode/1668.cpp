class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 1;
        while (sequence.find(repeat(word, res)) != string::npos)
            res ++ ;
        return res - 1;
    }

    string repeat(string s, int k) {
        string res;
        while (k -- ) res += s;
        return res;
    }
};