class Solution {
public:
    int ans;

    void doDel(vector<int>& vec, int r, int l) {
        int maxval = vec[l];
        int sum = 0;
        for(int i=l;i<=r;i++) {
            if(vec[i] > maxval)
                maxval = vec[i];
            sum += vec[i];
        }
        ans += sum - maxval;
    }

    int minCost(string s, vector<int>& vec) {
        int len = s.size();
        if(!len)
            return 0;
        ans = 0;
        set<pair<int,int>> st; // 区间
        int left = 0;
        char val = s[0];
        for(int i=0;i<len;i++) {
            if(s[i]==val) {
                continue;
            }
            else {
                if(i-1 - left > 0)
                    doDel(vec, i-1, left);
                left = i;
                val = s[i];
            }
        }
        if(len-1 - left > 0)
            doDel(vec, len-1, left);
        return ans;
    }
};