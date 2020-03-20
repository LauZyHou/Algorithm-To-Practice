class Solution {
public:
    int findString(vector<string>& v, string s) {
        int len = v.size();
        if(!len)
            return -1;
        int left = 0;
        while(left<len && v[left].size()==0)
            left++;
        int right = len-1;
        while(right>=0 && v[right].size()==0)
            right--;
        while(true) {
            if(left>right) // 为了continue能走判断所以扔到这里
                break;
            int mid = (left+right)/2;
            int mid_r = mid;
            int mid_l = mid;
            while(mid_r<=right && v[mid_r].size()==0)
                mid_r++;
            while(mid_l>=left && v[mid_l].size()==0)
                mid_l--;
            if(mid_r<=right) {
                string& val = v[mid_r];
                if(val<s) {
                    left = mid_r+1;
                    continue;
                } else if(val>s) {
                    right = min(mid_l, mid_r-1);
                    continue;
                } else {
                    return mid_r;
                }
            }
        }
        return -1;
    }
};