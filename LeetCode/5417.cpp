class Solution {
private:
    bool ok(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    int maxVowels(string s, int k) {
        int slen = s.size();
        int val = 0;
        int ans;
        // 第一个窗口
        for(int i=0;i<k;i++) {
            val += ok(s[i]);
        }
        ans = val;
        for(int i=1;i+k <= slen;i++) {
            val -= ok(s[i-1]);
            val += ok(s[i+k-1]);
            if(val > ans)
                ans = val;
        }
        return ans;
    }
};