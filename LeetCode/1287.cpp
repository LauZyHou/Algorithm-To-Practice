class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        int val = len/4+1; // > 25%
        for(int i=0;i<len;i+=val) {
            // 二分查找最小和最大下标
            auto low = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto up = upper_bound(arr.begin(), arr.end(), arr[i]);
            if(up-low>=val)
                return arr[i];
        }
        return -1;
    }
};