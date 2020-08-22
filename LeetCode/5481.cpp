class Solution {
public:
    bool check(vector<int>& v, int n) {
        for(int i=0;i<n;i++) {
            if(v[i])
                return true;
        }
        return false;
    }
    int minOperations(vector<int>& v) {
        int len = v.size();
        sort(v.begin(), v.end());
        int ans = 0;
        while(check(v,len)) { // 没全0
            for(int i=0;i<len;i++) {
                if(v[i]&1) {
                    v[i]--;
                    ans++;
                }
            }
            if(!check(v,len))
                break;
            for(int i=0;i<len;i++) {
                v[i]/=2;
            }
            ans++;
        }
        return ans;
    }
};