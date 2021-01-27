class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> left, right;
        int l = 0, r = 0;
        for (char c: s) {
            right[c] ++ ;
            if (right[c] == 1) r ++ ;
        }
        int res = 0;
        for (char c: s) {
            left[c] ++ , right[c] -- ;
            if (left[c] == 1) l ++ ;
            if (right[c] == 0) r -- ;
            if (l == r) res ++ ;
        }
        return res;
    }
};