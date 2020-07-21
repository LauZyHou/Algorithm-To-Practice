class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1+n2!=n3)
            return false;
        auto f = vector(n1+1, vector<bool>(n2+1, false));
        f[0][0] = true;
        for(int i=0;i<=n1;i++) {
            for(int j=0;j<=n2;j++) {
                int p = i+j-1;
                if(i > 0 && s1[i-1]==s3[p] && f[i-1][j]) {
                    f[i][j] = true; 
                }
                else if(j > 0 && s2[j-1]==s3[p] && f[i][j-1]) {
                    f[i][j] = true;
                }
            }
        }
        return f[n1][n2];
    }
};