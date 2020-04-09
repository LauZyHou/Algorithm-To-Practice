#include<vector>

class Solution {
public:
    int numSteps(string s) {
        // 反向bit vector
        bool bv[600];
        int len = s.size();
        for(int j=len-1;j>=0;j--){
            bv[len-1-j] = s[j]=='1' ? 1 : 0;
        }
        int i=0;
        int j=len;
        int ans = 0;
        while(j-i>1) { // 仅差一位时一定bv[i]是1
            if(bv[i]==1) {
                int r = i;
                for(;r<j;r++) {
                    if(bv[r])
                        bv[r]=0;
                    else {
                        bv[r]=1;
                        break;
                    }
                }
                if(r==j) {
                    j++;
                    bv[j-1] = 1;
                }
            }
            else {
                i++;
            }
            ans++;
        }
        return ans;
    }
};