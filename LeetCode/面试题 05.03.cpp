class Solution {
public:
    int reverseBits(int n) {
        int v[32] = {0};
        int i = 0;
        while(n) {
            if(n&1) {
                v[i]++;
            }
            else
                i++;
            n >>= 1;
        }
        int ans = 0;
        for(int j=0;j<=i;j++) {
            ans = max(ans, v[j]+v[j+1]+1);
        }
        return ans;
    }
};