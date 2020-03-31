class Solution {
public:
    int numTeams(vector<int>& v) {
        int len = v.size();
        int ans = 0;
        // <
        for(int i=0;i<=len-3;i++) {
            for(int j=i+1;j<=len-2;j++) {
                if(v[j]<=v[i])
                    continue;
                for(int k=j+1;k<len;k++) {
                    if(v[k]<=v[j])
                        continue;
                    ans++;
                }
            }
        }
        // >
        for(int i=0;i<=len-3;i++) {
            for(int j=i+1;j<=len-2;j++) {
                if(v[j]>=v[i])
                    continue;
                for(int k=j+1;k<len;k++) {
                    if(v[k]>=v[j])
                        continue;
                    ans++;
                }
            }
        }
        return ans;
    }
};