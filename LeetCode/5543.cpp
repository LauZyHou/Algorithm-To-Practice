class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        vector<int> a(26, 0);
        for (int i = 0; i < n; i ++)
            a[s[i] - 'a'] ++;
        for (int i = 0; i < 26; i ++) {
            if (a[i] > 1) {
                int l = 0, r = n - 1;
                while (s[l] != i + 'a')
                    l ++;
                while (s[r] != i + 'a')
                    r --;
                ans = max(ans, r - l - 1);
            }
        }
        return ans;
    }
};