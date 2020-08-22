class Solution {
public:
    int countGoodTriplets(vector<int>& v, int a, int b, int c) {
        int len = v.size();
        if(len < 3)
            return 0;
        int ans = 0;
        for (int i=0;i<len;i++) {
            for(int j=i+1;j<len;j++) {
                if(abs(v[i]-v[j])>a)
                    continue;
                for(int k=j+1;k<len;k++) {
                    if(abs(v[j]-v[k])>b || abs(v[i]-v[k])>c)
                        continue;
                    ans++;
                }
            }
        }
        return ans;
    }
};