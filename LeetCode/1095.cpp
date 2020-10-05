/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int bsearch(MountainArray &v, int l, int r, int t, bool rev = false) {
        while (l < r) {
            int mid = l + r >> 1;
            int val = v.get(mid);
            if (val > t)
                if (rev)
                    l = mid + 1;
                else
                    r = mid - 1;
            else if (val < t)
                if (rev)
                    r = mid - 1;
                else
                    l = mid + 1;
            else
                return mid;
        }
        return l;
    }
public:
    int findInMountainArray(int t, MountainArray &v) {
        int len = v.length();
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (v.get(mid) < v.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        int ans = bsearch(v, 0, l, t);
        if (v.get(ans) == t)
            return ans;
        ans =  bsearch(v, l, len - 1, t, true);
        if (v.get(ans) == t)
            return ans;
        return -1;
    }
};