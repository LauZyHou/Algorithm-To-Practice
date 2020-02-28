class Solution {
public:
    int maxProfit(vector<int> &v) {
        int len = v.size();
        if(len<2)
            return 0;
        int ans = 0;
        for(int i=1;i<len;i++)
            if(v[i]-v[i-1]>0)
                ans += v[i]-v[i-1];
        return ans;
    }
};