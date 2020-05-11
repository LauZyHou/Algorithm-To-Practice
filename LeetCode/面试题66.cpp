class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> ans(len);
        if(!len)
            return ans;
        int* left = new int[len];
        int* right = new int[len];
        left[0] = right[len-1] = 1;
        for(int i=1;i<len;i++) {
            left[i] = left[i-1] * a[i-1];
        }
        for(int i=len-2;i>=0;i--) {
            right[i] = right[i+1] * a[i+1];
        }
        for(int i=0;i<len;i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};