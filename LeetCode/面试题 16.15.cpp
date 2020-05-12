class Solution {
public:
    vector<int> masterMind(string s, string g) {
        int a[4] = {0}; // RYGB
        int b[4] = {0};
        for(char c : s) {
            if(c=='R')
                a[0]++;
            else if(c=='Y')
                a[1]++;
            else if(c=='G')
                a[2]++;
            else
                a[3]++;
        }
        for(char c : g) {
            if(c=='R')
                b[0]++;
            else if(c=='Y')
                b[1]++;
            else if(c=='G')
                b[2]++;
            else
                b[3]++;
        }
        int ans0 = 0;
        for(int i=0;i<4;i++)
            if(s[i]==g[i])
                ans0++;
        vector<int> ans(2, 0);
        ans[0] = ans0;
        for(int i=0;i<4;i++) {
            ans[1] += min(a[i], b[i]);
        }
        ans[1] -= ans0;
        return ans;
    }
};