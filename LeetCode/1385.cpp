class Solution {
public:
    int findTheDistanceValue(vector<int>& v1, vector<int>& v2, int d) {
        int len1 = v1.size();
        int len2 = v2.size();
        if(!len1 || !len2)
            return 0;
        sort(v2.begin(), v2.end());
        int ans = 0;
        for(auto &x : v1) {
            // 找第一个大于等于x的位置，不存在就返回end()
            // 所以返回end时pos==len2，pos-1一定是<=len2的
            int pos = lower_bound(v2.begin(), v2.end(), x) - v2.begin();
            bool ok = true;
            if (pos < len2)
                ok &= (v2[pos]-x > d);
            if (pos-1 >= 0)
                ok &= (x-v2[pos-1] > d);
            ans += ok;
        }
        return ans;
    }
};