class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        int len = v.size();
        int l = 0, r = len - 1;
        vector<int> ans(2);
        if (!len) {
            ans[0] = ans[1] = -1;
            return ans;
        }

        while (l < r) {
            int mid = l+r >> 1;
            if (v[mid] >= t)
                r = mid;
            else 
                l = mid + 1;
        }

        if (v[l] != t) {
            ans[0] = ans[1] = -1;
            return ans;
        }
        ans[0] = l;

        l = 0, r = len - 1;
        while (l < r) {
            int mid = l+r+1 >> 1;
            if (v[mid] <= t)
                l = mid;
            else
                r = mid - 1;
        }

        ans[1] = l;

        return ans;
    }
};