class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int n) {
        int len = v.size();
        vector<bool> ans(len, false);
        if(!len)
            return ans;
        int maxnum = v[0];
        for(int i=0;i<len;i++) {
            if(v[i]>maxnum)
                maxnum = v[i];
        }
        for(int i=0;i<len;i++) {
            if(v[i]+n>=maxnum)
                ans[i] = true;
        }
        return ans;
    }
};