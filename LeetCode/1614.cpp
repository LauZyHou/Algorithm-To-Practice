class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int l = 0;
        for (char c: s) {
            if (c == '(') l ++ , res = max(res, l);
            else if (c == ')') l -- ;
        }
        return res;
    }
};