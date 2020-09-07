typedef long long ll;

class Solution {
public:
    int search2(vector<int>& vec, ll vv) {
        int len = vec.size();
        int l = 0, r = len-1;
        int ret = 0;
        while(l<r) {
            ll val = (ll)vec[l] * (ll)vec[r];
            if(val == vv) {
                if(vec[l]==vec[r]) {
                    ret += (r-l+1)*(r-l)/2;
                    return ret;
                }
                else {
                    int a = vec[l];
                    int b = vec[r];
                    int cntl = 0, cntr = 0;
                    while(vec[l]==a)
                        l++, cntl++;
                    while(vec[r]==b)
                        r--, cntr++;
                    ret += cntl*cntr;
                }
            }
            else if(val < vv) {
                l++;
            }
            else {
                r--;
            }
        }
        return ret;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1<2 && n2<2)
            return 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = 0;
        for(ll v:nums1) {
            // 二分
            ans += search2(nums2, v*v);
        }
        for(ll v:nums2) {
            ans += search2(nums1, v*v);
        }
        return ans;
    }
};