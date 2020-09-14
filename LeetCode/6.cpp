class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int slen = s.size();
        vector<string> rows(min(numRows, slen));
        int r = 0;
        bool isDown = false;
        for (char c : s) {
            rows[r] += c;
            if (r==0 || r==numRows-1)
                isDown = !isDown;
            r += isDown ? 1 : -1;
        }
        string ans;
        for (auto& row : rows) {
            ans += row;
        }
        return ans;
    }
};