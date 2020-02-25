class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int cnt = 0;
        if(n&1) {
            ans[0] = 0;
            cnt = 1;
        }
        for(int i=1;i<=n/2;i++) {
            ans[cnt] = i;
            ans[cnt+1] = -i;
            cnt+=2;
        }
        return ans;
    }
};