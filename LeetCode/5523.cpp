class Solution {
public:
    int minOperations(vector<string>& v) {
        int cnt = 0;
        for (string s : v) {
            if (s[0]=='.' && s[1] == '.' && s[2] == '/')
                cnt = max(cnt - 1, 0);
            else if (s[0] == '.' && s[1] == '/')
                continue;
            else
                cnt++;
        }
        return cnt;
    }
};