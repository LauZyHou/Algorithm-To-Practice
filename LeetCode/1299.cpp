class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if(!n)
            return arr;
        vector<int> idx(n); // 记录每个右边最大的下标
        int maxv = arr[n-1];
        int maxidx = n-1;
        for(int i=n-2;i>=0;i--) {
            if(arr[i+1]>maxv) {
                maxv = arr[i+1];
                maxidx = i+1;
            }
            idx[i] = maxidx;
        }
        for(int i=0;i<n-1;i++) {
            arr[i] = arr[idx[i]];
        }
        arr[n-1] = -1;
        return arr;
    }
};